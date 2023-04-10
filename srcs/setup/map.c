/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:26:34 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/10 16:05:15 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"setup.h"

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
		else if (is_char_in_str(line[i], "01DNSWEnswe"))
			break ;
		else
			exit_with_message("invalid characters set in map");
		i--;
	}
	*last_not_of_valid_chars = '\0';
}

static void	set_start_pos(t_info *info, char direction, size_t x, size_t y)
{
	if (info->player.pos.x == 0 && info->player.pos.y == 0)
	{
		info->player.pos.x = x + 0.5;
		info->player.pos.y = y + 0.5;
	}
	else
		exit_with_message("duplicate starting point set");
	if (direction == 'N')
		info->player.yaw = NORTH;
	else if (direction == 'S')
		info->player.yaw = SOUTH;
	else if (direction == 'W')
		info->player.yaw = WEST;
	else if (direction == 'E')
		info->player.yaw = EAST;
}

static void	validate_map_line(t_info *info, char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (is_char_in_str(line[i], "NSWE"))
			set_start_pos(info, line[i], i, info->map_height);
		else if (is_char_in_str(line[i], "nswe"))
			info->enemy_num++;
		else if (is_char_in_str(line[i], "01 D"))
			;
		else
			exit_with_message("characters other than map set");
		i++;
	}
}

void	input_map(t_info *info, t_circ_list **map_list, char *line)
{
	static bool	is_map_finish = false;
	char		*map_line;
	size_t		map_line_width;

	if (!*map_list && !ft_strcmp(line, ""))
		return ;
	else if (*map_list && !ft_strcmp(line, ""))
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
	insert_list(map_list, map_line);
}
