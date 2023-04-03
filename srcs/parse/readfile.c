/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:36:27 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/03 12:23:53 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"parse.h"

static void	init_information(t_info *info)
{
	info->map_list = NULL;
	info->north_texture.data = NULL;
	info->south_texture.data = NULL;
	info->west_texture.data = NULL;
	info->east_texture.data = NULL;
	info->ceiling_color = 0;
	info->floor_color = 0;
}

static bool	is_valid_format(char *file_name)
{
	size_t	file_name_len;
	size_t	file_extension_len;

	file_name_len = ft_strlen(file_name);
	file_extension_len = ft_strlen(FILE_EXTENSION);
	if (file_name_len < file_extension_len)
		return (false);
	file_name += file_name_len - file_extension_len;
	if (!ft_strcmp(file_name, FILE_EXTENSION))
		return (true);
	return (false);
}

static bool	is_ready_to_read_map(t_info *info)
{
	if (!info->north_texture.data || !info->south_texture.data
		|| !info->east_texture.data || !info->west_texture.data
		|| !info->ceiling_color || !info->floor_color)
		return (false);
	return (true);
}

static void	input_texture_and_color(t_info *info, char *line)
{
	char	**split_line;
	size_t	size;

	split_line = ft_split(line, ' ');
	if (!split_line)
		exit_with_message("failed to allocate memory");
	size = count_split_size(split_line);
	if (size != 2)
		exit_with_message("invalid format for contents set at the map");
	if (!strcmp(split_line[0], "NO") || !strcmp(split_line[0], "SO")
		|| !strcmp(split_line[0], "WE") || !strcmp(split_line[0], "EA"))
		input_texture(info, split_line);
	else if (!strcmp(split_line[0], "F") || !strcmp(split_line[0], "C"))
		input_color(info, split_line);
	else
		exit_with_message("invalid format for contents set at the map");
	safe_free_char_double_pointer(&split_line);
}

static void	input_data(t_info *info, int fd)
{
	char	*line;
	char	*newline_pos;

	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		newline_pos = ft_strchr(line, '\n');
		if (newline_pos)
			*newline_pos = '\0';
		if (is_ready_to_read_map(info))
			input_map(info, line);
		else if (!ft_strcmp(line, EMPTY_STRING))
			;
		else
			input_texture_and_color(info, line);
		safe_free_char_pointer(&line);
	}
	if (!is_ready_to_read_map(info) || !info->map_list)
		exit_with_message("missing context in map file");
}

void	readfile(t_info *info, char *file_name)
{
	int	fd;

	init_information(info);
	if (!is_valid_format(file_name))
		exit_with_message("invalid format specified for map file");
	fd = open(file_name, O_RDONLY);
	if (fd == OPEN_ERROR)
		exit_with_message("failed to open map file");
	input_data(info, fd);
	close(fd);
	print_list(info->map_list);
}
