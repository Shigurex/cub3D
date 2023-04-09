/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:36:27 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/09 21:32:02 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"parse.h"

static void	init_information(t_info *info)
{
	info->map_width = 0;
	info->map_height = 0;
	info->map_list = NULL;
	info->north_xpm_img.address = NULL;
	info->south_xpm_img.address = NULL;
	info->west_xpm_img.address = NULL;
	info->east_xpm_img.address = NULL;
	info->ceiling_color = 0;
	info->floor_color = 0;
	info->player.x = 0;
	info->player.y = 0;
	info->direction = 0;
	info->eye_angle = 0;
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
	if (!info->north_xpm_img.address || !info->south_xpm_img.address
		|| !info->east_xpm_img.address || !info->west_xpm_img.address
		|| !info->ceiling_color || !info->floor_color)
		return (false);
	return (true);
}

static void	input_address(t_info *info, int fd)
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
		else
			input_texture(info, line);
		safe_free_char_pointer(&line);
	}
	if (!is_ready_to_read_map(info) || !info->map_list)
		exit_with_message("missing context in map file");
	else if (info->player.x == 0 && info->player.y == 0)
		exit_with_message("starting position not set");
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
	input_address(info, fd);
	close(fd);
	printf("%s, %d\n", __FILE__, __LINE__);
	print_list(info->map_list);
	printf("width: %zu, height: %zu\n", info->map_width, info->map_height);
	printf("starting point: (%f, %f), direction: %f\n", info->player.x, info->player.y, info->direction);
	make_map_from_list(info);
	clear_list(&info->map_list);
}
