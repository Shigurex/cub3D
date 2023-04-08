/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:21:58 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/05 00:53:47 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"parse.h"

static bool	is_next_closed(t_info *info, size_t x, size_t y)
{
	t_block	**map;

	map = info->map;
	if (x <= 0 || info->map_width <= x + 1
		|| y <= 0 || info->map_height <= y + 1)
		return (false);
	if (map[y - 1][x].type == NONE || map[y + 1][x].type == NONE
		|| map[y][x - 1].type == NONE || map[y][x + 1].type == NONE)
		return (false);
	return (true);
}

static void	validate_closed_map(t_info *info)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < info->map_height)
	{
		j = 0;
		while (j < info->map_width)
		{
			if (info->map[i][j].type == SPACE || info->map[i][j].type == DOOR)
			{
				if (!is_next_closed(info, j, i))
					exit_with_message("map file not closed");
			}
			j++;
		}
		i++;
	}
}

static void	input_map_by_line(t_info *info, t_block *map_line, char *line)
{
	size_t	i;
	size_t	line_len;

	line_len = ft_strlen(line);
	i = 0;
	while (i < info->map_width)
	{
		if (i >= line_len || line[i] == ' ')
			map_line[i].type = NONE;
		else if (line[i] == '0' || line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'W' || line[i] == 'E')
			map_line[i].type = SPACE;
		else if (line[i] == '1')
			map_line[i].type = WALL;
		else if (line[i] == 'D')
			map_line[i].type = DOOR;
		i++;
	}
}

void	make_map_from_list(t_info *info)
{
	t_circ_list	*list;
	t_circ_list	*first_list;
	size_t		i;

	info->map = malloc(sizeof(t_block *) * info->map_height);
	if (!info->map)
		exit_with_message("failed to allocate memory");
	list = info->map_list;
	if (!list)
		return ;
	first_list = list;
	list = list->next;
	i = 0;
	while (list != first_list)
	{
		info->map[i] = malloc(sizeof(t_block) * info->map_width);
		if (!info->map[i])
			exit_with_message("failed to allocate memory");
		input_map_by_line(info, info->map[i], list->str);
		list = list->next;
		i++;
	}
	validate_closed_map(info);
}

void	clear_map(t_info *info)
{
	t_block	**map;
	size_t	i;

	map = info->map;
	i = 0;
	while (i < info->map_height)
	{
		free(map[i]);
		i++;
	}
	free(map);
	info->map = NULL;
}
