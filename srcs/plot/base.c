/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:34:04 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/10 21:33:43 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"plot.h"

double	time1 = 0;
double	time2 = 0;
bool test = false;
/* test */	double	time_diff(void)
/* test */	{
/* test */		static long	p = {0};
/* test */		long		n;
/* test */		double	sec;
/* test */
/* test */		n = clock();
/* test */		sec = (n - p) * 1.0 / CLOCKS_PER_SEC;
/* test */		p = clock();
/* test */		return (sec);
/* test */	}


static void	plot_line(t_info *info, t_ray *ray, int x)
{
	double	y;
	double	pic_l;
	int		d;

if (test)
{Td(ray->img.height)}
	pic_l = tan((SIGHT_PITCH / 360.0) * M_PI) * ray->distance * 2 / ray->img.height;
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


//static void	plot_line(t_info *info, t_ray *ray, int x)
//{
//	int		y;
//	double	pitch;
//	double	height;
//
//	y = 0;
//	while (y < WIN_HEIGHT)
//	{
//		pitch = info->player.pitch + \
//			((double)y - WIN_HEIGHT / 2) / WIN_HEIGHT * SIGHT_PITCH;
//		height = 0.5 + ray->distance * \
//			cos(degree_to_radian(ray->yaw - info->player.yaw)) * \
//			tan(degree_to_radian(pitch));
//		if (height < 0)
//			my_pixel_put(&info->screens.base, x, y, info->textures.floor);
//		else if (height > 1)
//			my_pixel_put(&info->screens.base, x, y, info->textures.ceiling);
//		else
//			my_pixel_put(&info->screens.base, x, y, \
//				my_pixel_get(&ray->img, \
//				ray->img_col, \
//				height * (ray->img.width - 1)));
//		y++;
//	}
//}

void	plot_base(t_info *info)
{
	int		x;
	t_ray	ray;
	double	yaw;

	x = 0;
	while (x < WIN_WIDTH)
	{
if (x == WIN_WIDTH / 2)
	test = true;
else
	test = false;
		yaw = info->player.yaw + \
			(WIN_WIDTH / 2 - (double)x) / WIN_WIDTH * SIGHT_YAW;
		ray = check_intersection(info, yaw);
if (test)
{
Td(ray.yaw)
Td(ray.distance)
Td(ray.img.height)
Td(ray.img.width)
}
		ray.row_win = x;
		plot_line(info, &ray, x);//なんか重い
		x++;
	}
	mlx_put_image_to_window(info->mlx, info->win, \
		info->screens.base.address, 0, 0);
}
