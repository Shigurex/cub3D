/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:23:24 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/03 12:18:31 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"parse.h"

static t_texture	set_texture(t_info *info, char *relative_path)
{
	t_texture	texture;

	texture.data = mlx_xpm_file_to_image(info->mlx, relative_path, \
		&texture.width, &texture.height);
	if (!texture.data)
		exit_with_message("failed to read image file");
	return (texture);
}

void	input_texture(t_info *info, char **split_line)
{
	t_texture	*texture;

	texture = NULL;
	if (!strcmp(split_line[0], "NO"))
		texture = &info->north_texture;
	else if (!strcmp(split_line[0], "SO"))
		texture = &info->south_texture;
	else if (!strcmp(split_line[0], "WE"))
		texture = &info->west_texture;
	else if (!strcmp(split_line[0], "EA"))
		texture = &info->east_texture;
	else
		exit_with_message("invalid format for contents set at the texture");
	if (texture->data)
		exit_with_message("duplicate texture set");
	*texture = set_texture(info, split_line[1]);
}
