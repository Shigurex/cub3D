/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 00:54:45 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/10 02:06:59 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"setup.h"

int	close_window(t_info *info)
{
	clear_map(info);
	mlx_destroy_image(info->mlx, info->north_xpm_img.address);
	mlx_destroy_image(info->mlx, info->south_xpm_img.address);
	mlx_destroy_image(info->mlx, info->west_xpm_img.address);
	mlx_destroy_image(info->mlx, info->east_xpm_img.address);
	mlx_destroy_image(info->mlx, info->img.address);
	mlx_destroy_image(info->mlx, info->minimap.address);
	mlx_destroy_window(info->mlx, info->win);
	exit(EXIT_SUCCESS);
}

static void	init_img(t_info *info, t_img *img, int width, int height)
{
	img->address = mlx_new_image(info->mlx, width, height);
	img->data = mlx_get_data_addr(img->address, \
		&img->bpp, &img->size_l, &img->endian);
}

void	init_setup(t_info *info)
{
	info->win = mlx_new_window(info->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	mlx_hook(info->win, ON_DESTROY, 1L << 0, close_window, info);
	mlx_hook(info->win, ON_KEYDOWN, 1L << 0, handle_key_press_action, info);
	mlx_hook(info->win, ON_KEYUP, 1L << 0, handle_key_release_action, info);
	mlx_mouse_hide();
	init_img(info, &info->img, WIN_WIDTH, WIN_HEIGHT);
	init_img(info, &info->minimap, MINIMAP_WIDTH, MINIMAP_HEIGHT);
	info->key_flag = CLEAR_ALL;
	mlx_loop_hook(info->mlx, plot_screen, info);
}
