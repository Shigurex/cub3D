/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:51:24 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/16 21:59:48 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"setup.h"
#define RA1 RIGHT_ARM_1
#define RA2 RIGHT_ARM_2
#define RA3 RIGHT_ARM_3
#define LA1 LEFT_ARM_1
#define LA2 LEFT_ARM_2
#define LA3 LEFT_ARM_3

static void	init_textures(t_info *info)
{
	info->textures.north.address = NULL;
	info->textures.south.address = NULL;
	info->textures.west.address = NULL;
	info->textures.east.address = NULL;
	info->textures.ceiling = TRANSPARENT;
	info->textures.floor = TRANSPARENT;
	set_xpm_img(info, &info->textures.arms[RA1], "./imgs/arms/arm00.xpm");
	set_xpm_img(info, &info->textures.arms[RA2], "./imgs/arms/arm01.xpm");
	set_xpm_img(info, &info->textures.arms[RA3], "./imgs/arms/arm02.xpm");
	set_xpm_img(info, &info->textures.arms[LA1], "./imgs/arms/arm10.xpm");
	set_xpm_img(info, &info->textures.arms[LA2], "./imgs/arms/arm11.xpm");
	set_xpm_img(info, &info->textures.arms[LA3], "./imgs/arms/arm12.xpm");
	set_xpm_img(info, &info->textures.door, "./imgs/textures/iron_door.xpm");
	set_xpm_img(info, &info->textures.start, "./imgs/textures/op.xpm");
}

static void	init_character(t_character *character)
{
	character->pos.x = 0;
	character->pos.y = 0;
	character->yaw = 0;
	character->pitch = 0;
	character->time = 0;
}

void	init_img(t_info *info, t_img *img, int width, int height)
{
	img->width = width;
	img->height = height;
	img->address = mlx_new_image(info->mlx, width, height);
	if (!img->address)
		exit_with_message("error occurred while initializing image");
	img->data = mlx_get_data_addr(img->address, \
		&img->bpp, &img->size_l, &img->endian);
}

void	init_basic_info(t_info *info)
{
	info->mlx = mlx_init();
	info->map_width = 0;
	info->map_height = 0;
	init_textures(info);
	init_character(&info->player);
	info->keys = CLEAR_ALL;
}
