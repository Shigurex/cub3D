/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 02:28:35 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/10 10:38:06 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"plot.h"

static unsigned int	get_img_color(t_xpm_img *img, int x, int y)
{
	void	*dst;

	if (x < 0 || img->width <= x || y < 0 || img->height <= y)
		return (TRANSPARENT);
	dst = img->data + (y * img->size_l + x * (img->bpp / 8));
	return (*(unsigned int *)dst);
}

static void	plot_line(t_info *info, t_intersection intersection, int x)
{
	size_t	i;
	double	elevation_angle;
	double	intersection_height;

	i = 0;
	while (i < WIN_HEIGHT)
	{
		elevation_angle = degree_to_radian(info->eye_angle + \
			((double)i - WIN_HEIGHT / 2) / WIN_HEIGHT * VERTICAL_SIGHT_ANGLE);
		intersection_height = HEIGHT + \
			intersection.distance_plot * tan(elevation_angle);
		if (intersection_height < 0)
			my_pixel_put(&info->img, x, i, info->floor_color);
		else if (intersection_height > 1)
			my_pixel_put(&info->img, x, i, info->ceiling_color);
		else
			my_pixel_put(&info->img, x, i, get_img_color(&intersection.xpm_img, \
				intersection.xpm_img_col, \
				(intersection.xpm_img.height - 1) * intersection_height));
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
