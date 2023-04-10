/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:57:47 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/10 17:07:20 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"setup.h"

static bool	is_valid_format(char *file_name, char *file_extension)
{
	size_t	file_name_len;
	size_t	file_extension_len;

	file_name_len = ft_strlen(file_name);
	file_extension_len = ft_strlen(file_extension);
	if (file_name_len < file_extension_len)
		return (false);
	file_name += file_name_len - file_extension_len;
	if (!ft_strcmp(file_name, file_extension))
		return (true);
	return (false);
}

static bool	is_ready_to_read_map(t_info *info)
{
	if (!info->textures.north.address || !info->textures.south.address
		|| !info->textures.west.address || !info->textures.east.address
		|| info->textures.ceiling == TRANSPARENT
		|| info->textures.floor == TRANSPARENT)
		return (false);
	return (true);
}

static t_circ_list	*get_map_info(t_info *info, int fd)
{
	char		*line;
	char		*newline_pos;
	t_circ_list	*map_list;

	map_list = NULL;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		newline_pos = ft_strchr(line, '\n');
		if (newline_pos)
			*newline_pos = '\0';
		if (is_ready_to_read_map(info))
			input_map(info, &map_list, line);
		else
			input_texture(info, line);
		safe_free_char_pointer(&line);
	}
	if (!is_ready_to_read_map(info) || !map_list)
		exit_with_message("missing context in map file");
	else if (info->player.pos.x == 0 && info->player.pos.y == 0)
		exit_with_message("starting position not set");
	return (map_list);
}

void	read_map_file(t_info *info, char *file_name)
{
	int			fd;
	t_circ_list	*map_list;

	if (!is_valid_format(file_name, FILE_EXTENSION))
		exit_with_message("invalid format specified for map file");
	fd = open(file_name, O_RDONLY);
	if (fd == OPEN_ERR)
		exit_with_message("failed to open map file");
	map_list = get_map_info(info, fd);
	close(fd);
	make_map_from_list(info, map_list);
	clear_list(&map_list);
	printf("map:\n");
	for (int i = (int)info->map_height - 1; i >= 0; i--)
	{
		for (int j = 0; j < (int)info->map_width; j++)
		{
			if (info->map[i][j].type == SPACE || info->map[i][j].type == NONE)
				printf(" ");
			else
				printf("X");
		}
		printf("\n");
	}
	printf("width: %zu, height: %zu\n", info->map_width, info->map_height);
	printf("starting point: (%f, %f), direction: %f\n", info->player.pos.x, info->player.pos.y, info->player.yaw);
	printf("%s, %d\n", __FILE__, __LINE__);
	fflush(stdout);
}
