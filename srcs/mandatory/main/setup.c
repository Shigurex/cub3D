/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:09:41 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/09 17:17:07 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../../includes/cub3D.h"

int	close_window(t_info *info)
{
	mlx_destroy_image(info->mlx, info->img.address);
	mlx_destroy_window(info->mlx, info->win);
	exit(EXIT_SUCCESS);
}

void	move_view(t_info *info, int keycode)
{
	if (keycode == LEFT)
		info->direction -= 10;
	else if (keycode == RIGHT)
		info->direction += 10;
}

void	move_direction(t_info *info, int keycode)
{
	if (keycode == W)
		info->player.y -= 0.1;
	else if (keycode == A)
		info->player.x -= 0.1;
	else if (keycode == S)
		info->player.y += 0.1;
	else if (keycode == D)
		info->player.x += 0.1;
}

int	handle_key_input(int keycode, t_info *info)
{
	if (keycode == ESC)
		close_window(info);
	else if (keycode == LEFT || keycode == RIGHT)
		move_view(info, keycode);
	else if (keycode == W || keycode == A || keycode == S || keycode == D)
		move_direction(info, keycode);
	return (0);
}
