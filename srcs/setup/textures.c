/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:26:50 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/10 14:39:07 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"setup.h"

static void	set_xpm_img(t_info *info, t_img *img, char *relative_path)
{
	img->address = mlx_xpm_file_to_image(info->mlx, relative_path, \
		&img->width, &img->height);
	if (!img->address)
		exit_with_message("error occurred while getting image");
	img->data = mlx_get_data_addr(img->address, \
		&img->bpp, &img->size_l, &img->endian);
	if (img->width == 0 || img->height == 0)
		exit_with_message("failed to read image file");
}

static size_t	count_split_size(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	input_xpm_img(t_info *info, char **split_line)
{
	t_img	*xpm_img;

	xpm_img = NULL;
	if (!strcmp(split_line[0], "NO"))
		xpm_img = &info->textures.north;
	else if (!strcmp(split_line[0], "SO"))
		xpm_img = &info->textures.south;
	else if (!strcmp(split_line[0], "WE"))
		xpm_img = &info->textures.west;
	else if (!strcmp(split_line[0], "EA"))
		xpm_img = &info->textures.east;
	else
		exit_with_message("invalid format for contents set at the xpm image");
	if (xpm_img->address)
		exit_with_message("duplicate xpm_img set");
	set_xpm_img(info, xpm_img, split_line[1]);
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
	if (count_split_size(colors) != 3) //neee
		exit_with_message("invalid format for contents set at the color");
	red = atoi_color(colors[0]);
	green = atoi_color(colors[1]);
	blue = atoi_color(colors[2]);
	if (!strcmp(split_line[0], "F"))
		info->textures.floor = trgb_to_color(0, red, green, blue);
	else if (!strcmp(split_line[0], "C"))
		info->textures.ceiling = trgb_to_color(0, red, green, blue);
	else
		exit_with_message("invalid format for contents set at the color");
	safe_free_char_double_pointer(&colors);
}

void	input_texture(t_info *info, char *line)
{
	char	**split_line;
	size_t	size;

	if (!ft_strcmp(line, ""))
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
