/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 02:28:35 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/09 21:32:58 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"plot.h"

static void	plot_line(t_info *info, t_intersection intersection, int x)
{
	size_t	i;
	double	elevation_angle;
	double	intersection_height;

	i = 0;
	elevation_angle = degree_to_radian(info->eye_angle);
	while (i < WIN_HEIGHT)
	{
		elevation_angle = degree_to_radian(info->eye_angle + \
			((double)i - WIN_HEIGHT / 2) / WIN_HEIGHT * VERTICAL_SIGHT_ANGLE);
		intersection_height = HEIGHT + intersection.distance * tan(elevation_angle);
		// printf("%f\n", intersection_height);
		if (intersection_height < 0)
			my_pixel_put(&info->img, x, i, info->floor_color);
		else if (intersection_height >= 1)
			my_pixel_put(&info->img, x, i, info->ceiling_color);
		else
			my_pixel_put(&info->img, x, i, WHITE);
		i++;
	}
}

void	plot_view(t_info *info)
{
	int				i;
	double			ray_angle;
	t_intersection	intersecion;

	i = 0;
	while (i < WIN_WIDTH)
	{
		ray_angle = degree_to_radian(info->direction + \
			((double)i - WIN_WIDTH / 2) / WIN_WIDTH * HORIZONTAL_SIGHT_ANGLE);
		intersecion = check_intersection(info, ray_angle);
		plot_line(info, intersecion, i);
		i++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.address, 0, 0);
}
