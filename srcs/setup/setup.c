/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 00:54:45 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/03 12:12:59 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"setup.h"

int	close_window(t_info *info)
{
	mlx_destroy_image(info->mlx, info->img.address);
	mlx_destroy_window(info->mlx, info->win);
	exit(EXIT_SUCCESS);
}

void	init_setup(t_info *info)
{
	info->win = mlx_new_window(info->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	mlx_hook(info->win, ON_DESTROY, 1L << 0, close_window, info);
	mlx_hook(info->win, ON_KEYDOWN, 1L << 0, handle_key_input, info);
	//mlx_hook(info->mlx, ON_EXPOSE, 0L, NULL, NULL);
	info->img.address = mlx_new_image(info->mlx, WIN_WIDTH, WIN_HEIGHT);
	info->img.data = mlx_get_data_addr(info->img.address, \
		&info->img.bpp, &info->img.size_l, &info->img.endian);
}
