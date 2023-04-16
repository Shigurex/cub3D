/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:34:04 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/16 21:51:19 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"plot.h"

static void	plot_line(t_info *info, t_ray *ray, int x)
{
	double	y;
	double	pic_l;
	int		d;

	pic_l = cos(((info->player.yaw - ray->yaw) / 180.0) * M_PI) \
		* ray->distance * 2 * ray->img.height / 40 / 40;
	d = WIN_HEIGHT / 2 - 1;
	y = ray->img.height / 2 - MINI_NUM;
	while (d >= 0)
	{
		if (y >= 0)
		{
			my_pixel_put(&info->screens.base, x, d, my_pixel_get(&ray->img, \
				ray->img_col, (int)floor(y)));
			y -= pic_l;
		}
		else
			my_pixel_put(&info->screens.base, x, d, info->textures.ceiling);
		d--;
	}
	d = WIN_HEIGHT / 2;
	y = ray->img.height / 2;
	while (d < WIN_HEIGHT)
	{
		if (y < ray->img.height)
		{
			my_pixel_put(&info->screens.base, x, d, my_pixel_get(&ray->img, \
				ray->img_col, (int)floor(y)));
			y += pic_l;
		}
		else
			my_pixel_put(&info->screens.base, x, d, info->textures.floor);
		d++;
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
		ray.row_win = x;
		plot_line(info, &ray, x);
		x++;
	}
	mlx_put_image_to_window(info->mlx, info->win, \
		info->screens.base.address, 0, 0);
}
