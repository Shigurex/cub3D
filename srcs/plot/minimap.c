/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:58:58 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/08 18:43:00 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"plot.h"

static t_pos	get_minimap_pos_from_ratio(t_info *info, \
	double x_ratio, double y_ratio)
{
	t_pos	pos;

	pos.x = (info->player.x - (double)MINIMAP_SIZE / 2) \
		+ MINIMAP_SIZE * x_ratio;
	pos.y = (info->player.y - (double)MINIMAP_SIZE / 2) \
		+ MINIMAP_SIZE * y_ratio;
	return (pos);
}

static unsigned int	get_color_of_minimap_pos(t_info *info, t_pos pos)
{
	int	x;
	int	y;

	x = floor(pos.x);
	y = floor(pos.y);
	if (x < 0 || (int)info->map_width <= x || y < 0 || (int)info->map_height <= y)
		return (SILVER);
	else if (info->map[y][x].type == NONE)
		return (SILVER);
	else if ((info->player.x - 0.05 <= pos.x && pos.x <= info->player.x + 0.05) && (info->player.y - 0.05 <= pos.y && pos.y <= info->player.y + 0.05))
		return (BLACK);
	else if (((double)x - 0.03 <= pos.x && pos.x <= (double)x + 0.03) || ((double)y - 0.03 <= pos.y && pos.y <= (double)y + 0.03))
		return (BLACK);
	else if (info->map[y][x].type == WALL)
		return (GRAY);
	return (WHITE);
}

void	plot_minimap(t_info *info)
{
	int		i;
	int		j;
	t_pos	pos;

	i = 0;
	while (i < MINIMAP_HEIGHT)
	{
		j = 0;
		while (j < MINIMAP_WIDTH)
		{
			pos = get_minimap_pos_from_ratio(info, \
				(double)j / MINIMAP_WIDTH, (double)i / MINIMAP_HEIGHT);
			//printf("(%f %f)\n", pos.x, pos.y);
			(void)pos;
			my_pixel_put(&info->minimap, j, i, get_color_of_minimap_pos(info, pos));
			j++;
		}
		i++;
	}
	//for (double angle = 0; angle < 400; angle += 10) {
	//	t_intersection intersection = check_intersection(info, degree_to_radian(angle));
	//	printf("angle %f: %f %f\n", angle, intersection.pos.x, intersection.pos.y);
	//	//printf("distance: %f\n", intersection.distance);
	//	//printf("axis: %d\n", intersection.axis);
	//	//printf("type: %d\n\n", intersection.type);
	//}
	mlx_put_image_to_window(info->mlx, info->win, \
		info->minimap.address, 20, 20);
	//mlx_put_image_to_window(info->mlx, info->win, \
	//	info->minimap.address, 20, 20);
}
