/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:51:39 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/05 00:50:40 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"parse.h"

static void	get_map_line(char *line)
{
	size_t	i;
	char	*last_not_of_valid_chars;

	i = ft_strlen(line);
	if (i == 0)
		return ;
	while (i > 0)
	{
		if (line[i] == ' ' || line[i] == '\0')
			last_not_of_valid_chars = &line[i];
		else if (line[i] == '0' || line[i] == '1' || line[i] == 'N'
			|| line[i] == 'S' || line[i] == 'E' || line[i] == 'W'
			|| line[i] == 'D')
			break ;
		else
			exit_with_message("invalid characters set in map");
		i--;
	}
	*last_not_of_valid_chars = '\0';
}

static void	set_start_pos(t_info *info, char direction, size_t x, size_t y)
{
	if (info->player.x == 0 && info->player.y == 0)
	{
		info->player.x = x + 0.5;
		info->player.y = y + 0.5;
	}
	else
		exit_with_message("duplicate starting point set");
	if (direction == 'N')
		info->direction = NORTH;
	else if (direction == 'S')
		info->direction = SOUTH;
	else if (direction == 'W')
		info->direction = WEST;
	else if (direction == 'E')
		info->direction = EAST;
}

static void	validate_map_line(t_info *info, char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'W' || line[i] == 'E')
			set_start_pos(info, line[i], i, info->map_height);
		else if (line[i] == '0' || line[i] == '1'
			|| line[i] == ' ' || line[i] == 'D')
			;
		else
			exit_with_message("characters other than map set");
		i++;
	}
}

void	input_map(t_info *info, char *line)
{
	static bool	is_map_finish = false;
	char		*map_line;
	size_t		map_line_width;

	if (!info->map_list && !ft_strcmp(line, EMPTY_STRING))
		return ;
	else if (info->map_list && !ft_strcmp(line, EMPTY_STRING))
		is_map_finish = true;
	else if (is_map_finish)
		exit_with_message("information written after the map end");
	validate_map_line(info, line);
	get_map_line(line);
	map_line = ft_strdup(line);
	if (!map_line)
		exit_with_message("failed to allocate memory");
	map_line_width = ft_strlen(map_line);
	if (map_line_width > info->map_width)
		info->map_width = map_line_width;
	info->map_height++;
	insert_list(&info->map_list, map_line);
}
