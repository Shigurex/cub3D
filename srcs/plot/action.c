/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:04:04 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/10 21:17:35 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"plot.h"

void	move_view(t_info *info)
{
	if (info->keys & ROTATE_LEFT)
		info->player.yaw += ROTATE_SPEED;
	if (info->keys & ROTATE_RIGHT)
		info->player.yaw -= ROTATE_SPEED;
	info->player.yaw = convert_degree_within_two_pie(info->player.yaw);
}

static double	calculate_moving_angle(t_info *info)
{
	double	angle;
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (info->keys & MOVE_FORWARD)
		x++;
	if (info->keys & MOVE_BACKWARD)
		x--;
	if (info->keys & MOVE_LEFT)
		y++;
	if (info->keys & MOVE_RIGHT)
		y--;
	if (x == 0 && y == 0)
		return (DBL_MAX);
	angle = info->player.yaw + atan2(y, x) / (2 * M_PI) * 360;
	return (angle);
}

void	move_direction(t_info *info)
{
	double	angle;
	double	angle_radian;
	t_pos	moved_pos;
	t_ray	ray;

	angle = calculate_moving_angle(info);
	angle_radian = degree_to_radian(angle);
	if (angle == DBL_MAX)
		return ;
	moved_pos = assign_pos(info->player.pos.x + SPEED * cos(angle_radian), \
		info->player.pos.y + SPEED * sin(angle_radian));
	ray = check_intersection(info, angle);
	if (calculate_distance(info->player.pos, moved_pos) \
		< calculate_distance(info->player.pos, ray.pos))
		info->player.pos = assign_pos(moved_pos.x, moved_pos.y);
}
