/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:04:04 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/09 01:41:30 by yahokari         ###   ########.fr       */
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

static t_pos	get_moved_pos(t_info *info)
{
	double	angle;
	t_pos	moved_pos;

	angle = degree_to_radian(info->direction);
	if (info->key_flag & MOVE_FORWARD)
		info->player = assign_pos(info->player.x + SPEED * cos(angle), \
			info->player.y + SPEED * sin(angle));
	if (info->key_flag & MOVE_BACKWORD)
		info->player = assign_pos(info->player.x - SPEED * cos(angle), \
			info->player.y - SPEED * sin(angle));
	if (info->key_flag & MOVE_LEFT)
		info->player = assign_pos(info->player.x + SPEED * cos(angle - M_PI_2), \
			info->player.y + SPEED * sin(angle - M_PI_2));
	if (info->key_flag & MOVE_RIGHT)
		info->player = assign_pos(info->player.x - SPEED * cos(angle - M_PI_2), \
			info->player.y - SPEED * sin(angle - M_PI_2));
	moved_pos.x = info->player.x;
	moved_pos.y = info->player.y;
	//printf("(%f, %f)\n", moved_pos.x, moved_pos.y);
	return (moved_pos);
}

void	move_direction(t_info *info) // need modified
{
	t_pos	moved_pos;

	moved_pos = get_moved_pos(info);
	//printf("(%f, %f)\n", moved_pos.x, moved_pos.y);
	(void)moved_pos;
	//printf("(%f, %f)\n", moved_pos.x, moved_pos.y);
	//info->player.x = moved_pos.x;
	//info->player.y = moved_pos.y;
}
