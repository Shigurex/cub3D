/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:23:24 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/09 22:10:20 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"parse.h"

static t_xpm_img	set_xpm_img(t_info *info, char *relative_path)
{
	t_xpm_img	xpm_img;

	xpm_img.address = mlx_xpm_file_to_image(info->mlx, relative_path, \
		&xpm_img.width, &xpm_img.height);
	xpm_img.data = mlx_get_data_addr(xpm_img.address, \
		&xpm_img.bpp, &xpm_img.size_l, &xpm_img.endian);
	if (!xpm_img.address || xpm_img.width == 0 || xpm_img.height == 0)
		exit_with_message("failed to read image file");
	return (xpm_img);
}

static void	input_xpm_img(t_info *info, char **split_line)
{
	t_xpm_img	*xpm_img;

	xpm_img = NULL;
	if (!strcmp(split_line[0], "NO"))
		xpm_img = &info->north_xpm_img;
	else if (!strcmp(split_line[0], "SO"))
		xpm_img = &info->south_xpm_img;
	else if (!strcmp(split_line[0], "WE"))
		xpm_img = &info->west_xpm_img;
	else if (!strcmp(split_line[0], "EA"))
		xpm_img = &info->east_xpm_img;
	else
		exit_with_message("invalid format for contents set at the xpm image");
	if (xpm_img->address)
		exit_with_message("duplicate xpm_img set");
	*xpm_img = set_xpm_img(info, split_line[1]);
}

static int	atoi_color(char *str)
{
	int		num;
	size_t	i;

	num = 0;
	i = 0;
	while (str[i] && i < 3)
	{
		if (!isdigit(str[i]))
			exit_with_message("invalid character used for color");
		num = num * 10 + str[i] - '0';
		if (num > 255)
			exit_with_message("number out of range specified for color");
		i++;
	}
	if (str[i])
		exit_with_message("number out of range specified for color");
	return (num);
}

static void	input_color(t_info *info, char **split_line)
{
	char	**colors;
	int		red;
	int		green;
	int		blue;

	colors = ft_split(split_line[1], ',');
	if (count_split_size(colors) != 3)
		exit_with_message("invalid format for contents set at the color");
	red = atoi_color(colors[0]);
	green = atoi_color(colors[1]);
	blue = atoi_color(colors[2]);
	if (!strcmp(split_line[0], "F"))
		info->floor_color = rgb_to_color(red, green, blue);
	else if (!strcmp(split_line[0], "C"))
		info->ceiling_color = rgb_to_color(red, green, blue);
	else
		exit_with_message("invalid format for contents set at the color");
	safe_free_char_double_pointer(&colors);
}

void	input_texture(t_info *info, char *line)
{
	char	**split_line;
	size_t	size;

	if (!ft_strcmp(line, EMPTY_STRING))
		return ;
	split_line = ft_split(line, ' ');
	if (!split_line)
		exit_with_message("failed to allocate memory");
	size = count_split_size(split_line);
	if (size != 2)
		exit_with_message("invalid format for contents set at the map");
	if (!strcmp(split_line[0], "NO") || !strcmp(split_line[0], "SO")
		|| !strcmp(split_line[0], "WE") || !strcmp(split_line[0], "EA"))
		input_xpm_img(info, split_line);
	else if (!strcmp(split_line[0], "F") || !strcmp(split_line[0], "C"))
		input_color(info, split_line);
	else
		exit_with_message("invalid format for contents set at the map");
	safe_free_char_double_pointer(&split_line);
}
