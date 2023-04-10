/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:34:04 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/10 21:15:47 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"plot.h"

static void	plot_line(t_info *info, t_ray ray, int x)
{
	int		y;
	double	pitch;
	double	height;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		pitch = info->player.pitch + \
			((double)y - WIN_HEIGHT / 2) / WIN_HEIGHT * SIGHT_PITCH;
		height = 0.5 + ray.distance * cos(degree_to_radian(ray.yaw - info->player.yaw)) * tan(degree_to_radian(pitch));
		if (height < 0)
			my_pixel_put(&info->screens.base, x, y, info->textures.floor);
		else if (height > 1)
			my_pixel_put(&info->screens.base, x, y, info->textures.ceiling);
		else
			my_pixel_put(&info->screens.base, x, y, \
				my_pixel_get(ray.img, \
				ray.img_col, \
				height * (ray.img.width - 1)));
		y++;
	}
}

void	plot_base(t_info *info)
{
	int		x;
	t_ray	ray;
	double	yaw;

	x = 0;
	while (x < WIN_WIDTH)
	{
		yaw = info->player.yaw + \
			(WIN_WIDTH / 2 - (double)x) / WIN_WIDTH * SIGHT_YAW;
		ray = check_intersection(info, yaw);
		plot_line(info, ray, x);
		x++;
	}
	mlx_put_image_to_window(info->mlx, info->win, \
		info->screens.base.address, 0, 0);
}
