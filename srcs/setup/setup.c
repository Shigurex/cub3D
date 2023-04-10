/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:21:26 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/10 17:01:11 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"setup.h"

int	close_window(t_info *info)
{
	if (info->enemy_num > 0)
		free(info->enemy);
	clear_map(info);
	mlx_destroy_image(info->mlx, info->textures.north.address);
	mlx_destroy_image(info->mlx, info->textures.south.address);
	mlx_destroy_image(info->mlx, info->textures.west.address);
	mlx_destroy_image(info->mlx, info->textures.east.address);
	mlx_destroy_image(info->mlx, info->screens.base.address);
	mlx_destroy_image(info->mlx, info->screens.enermy.address);
	mlx_destroy_image(info->mlx, info->screens.minimap.address);
	mlx_destroy_window(info->mlx, info->win);
	exit(EXIT_SUCCESS);
}

static void	setup_mlx(t_info *info)
{
	info->win = mlx_new_window(info->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	mlx_hook(info->win, ON_DESTROY, 1L << 0, close_window, info);
	mlx_hook(info->win, ON_KEYDOWN, 1L << 0, handle_key_press_action, info);
	mlx_hook(info->win, ON_KEYUP, 1L << 0, handle_key_release_action, info);
	init_img(info, &info->screens.base, WIN_WIDTH, WIN_HEIGHT);
	init_img(info, &info->screens.enermy, WIN_WIDTH, WIN_HEIGHT);
	init_img(info, &info->screens.minimap, WIN_WIDTH, WIN_HEIGHT);
	mlx_loop_hook(info->mlx, plot_screen, info);
}

void	setup_info(t_info *info, char *file_name)
{
	init_basic_info(info);
	read_map_file(info, file_name);
	setup_mlx(info);
}
