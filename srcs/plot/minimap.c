/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:58:58 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/10 21:30:27 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"plot.h"

static t_pos	get_minimap_pos_from_ratio(t_info *info, \
	double x_ratio, double y_ratio)
{
	t_pos	pos;

	pos.x = (info->player.pos.x - (double)MINIMAP_SIZE / 2) \
		+ MINIMAP_SIZE * x_ratio;
	pos.y = (info->player.pos.y - (double)MINIMAP_SIZE / 2) \
		+ MINIMAP_SIZE * y_ratio;
	return (pos);
}

static unsigned int	get_color_of_minimap_pos(t_info *info, t_pos pos)
{
	int	x;
	int	y;

	x = floor(pos.x);
	y = floor(pos.y);
	if (x < 0 || (int)info->map_width <= x
		|| y < 0 || (int)info->map_height <= y)
		return (SILVER);
	else if (info->map[y][x].type == NONE)
		return (SILVER);
	else if ((info->player.pos.x - 0.05 <= pos.x && pos.x <= info->player.pos.x + 0.05) && (info->player.pos.y - 0.05 <= pos.y && pos.y <= info->player.pos.y + 0.05))
		return (BLACK);
	else if (((double)x - 0.03 <= pos.x && pos.x <= (double)x + 0.03) || ((double)y - 0.03 <= pos.y && pos.y <= (double)y + 0.03))
		return (BLACK);
	else if (info->map[y][x].type == WALL)
		return (GRAY);
	return (WHITE);
}

void	plot_minimap(t_info *info)
{
	int		x;
	int		y;
	t_pos	pos;

	y = 0;
	while (y < MINIMAP_HEIGHT)
	{
		x = 0;
		while (x < MINIMAP_WIDTH)
		{
			pos = get_minimap_pos_from_ratio(info, \
				(double)x / MINIMAP_WIDTH, 1 - (double)y / MINIMAP_HEIGHT);
			my_pixel_put(&info->screens.minimap, x, y, \
				get_color_of_minimap_pos(info, pos));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(info->mlx, info->win, \
		info->screens.minimap.address, WIN_WIDTH / 60, WIN_HEIGHT / 45);
}
