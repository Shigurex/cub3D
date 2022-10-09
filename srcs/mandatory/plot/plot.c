/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 00:08:28 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/10 03:16:25 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../../includes/plot.h"

void	plot_col(t_info *info, size_t col, t_intersection *intersec, double height)
{
	size_t			i;
	size_t			wall_top;
	size_t			wall_bottom;
	//unsigned int	data[BL];

	i = 0;
	(void)intersec;
	(void)col;
	(void)info;
	wall_top = DIS_Y * (BL - height) / (BL * 2);
	wall_bottom = DIS_Y - wall_top;
	while (i < DIS_Y)
	{
		if (wall_top <= i && i <= wall_bottom)
		{
			//my_pixel_put(info, col, i, data[(BL - 1) * (i - wall_top) / (wall_bottom - wall_top)]);
			my_pixel_put(info, col, i, 0xFFFFFF);
		}
		else if (i < wall_top)
			my_pixel_put(info, col, i, 0x46E1FC);
		else
			my_pixel_put(info, col, i, 0xAA5D00);
		i++;
	}
}

void	plot_screen(t_info *info)
{
	size_t			i;
	t_intersection	intersec;
	double			angle;
	double			height;

	i = 0;
	while (i < DIS_X)
	{
		angle = info->direction + ((double)i - DIS_X / 2) / DIS_X * SIGHT;
		intersec = check_intersection(info, convert_to_radian(angle));
		height = BL / (2 * intersec.distance * tan(convert_to_radian(SIGHT / 2)));
		plot_col(info, i, &intersec, height);
		i++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.address, 0, 0);
}
