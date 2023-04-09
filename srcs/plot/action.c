/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:04:04 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/09 20:16:30 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"plot.h"

void	move_view(t_info *info)
{
	if (info->key_flag & ROTATE_LEFT)
		info->direction -= ROTATE_SPEED;
	if (info->key_flag & ROTATE_RIGHT)
		info->direction += ROTATE_SPEED;
	info->direction = convert_degree_within_two_pie(info->direction);
}

static double	calculate_moving_angle(t_info *info)
{
	double	angle;
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (info->key_flag & MOVE_FORWARD)
		x++;
	if (info->key_flag & MOVE_BACKWORD)
		x--;
	if (info->key_flag & MOVE_RIGHT)
		y++;
	if (info->key_flag & MOVE_LEFT)
		y--;
	if (x == 0 && y == 0)
		return (DBL_MAX);
	angle = info->direction + atan2(y, x) / (2 * M_PI) * 360;
	angle = degree_to_radian(angle);
	return (angle);
}

void	move_direction(t_info *info)
{
	double			angle;
	t_pos			moved_pos;
	t_intersection	intersection;

	angle = calculate_moving_angle(info);
	if (angle == DBL_MAX)
		return ;
	moved_pos = assign_pos(info->player.x + SPEED * cos(angle), \
		info->player.y + SPEED * sin(angle));
	intersection = check_intersection(info, angle);
	if (calculate_distance(info->player, moved_pos) \
		< calculate_distance(info->player, intersection.pos))
		info->player = assign_pos(moved_pos.x, moved_pos.y);
}
