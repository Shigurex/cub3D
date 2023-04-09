/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 01:51:57 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/09 02:38:04 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"raycasting.h"

static t_pos	calculate_bumped_block_pos(t_pos ray, double angle, t_axis axis)
{
	t_pos	block_pos;

	if (axis == HORIZONTAL && (0 < angle && angle < M_PI))
		block_pos = assign_pos(floor(ray.x), round(ray.y));
	else if (axis == HORIZONTAL && (M_PI < angle && angle < 2 * M_PI))
		block_pos = assign_pos(floor(ray.x), round(ray.y - 1));
	else if (axis == VERTICAL && ((0 <= angle && angle < M_PI_2) \
		|| (3 * M_PI_2 < angle && angle < 2 * M_PI)))
		block_pos = assign_pos(round(ray.x), floor(ray.y));
	else if (axis == VERTICAL && (M_PI_2 < angle && angle < 3 * M_PI_2))
		block_pos = assign_pos(round(ray.x - 1), floor(ray.y));
	else
		block_pos = assign_pos(-1, -1);
	return (block_pos);
}

t_type	get_bumped_block(t_info *info, t_pos ray, double angle, t_axis axis)
{
	t_pos	block_pos;

	block_pos = calculate_bumped_block_pos(ray, angle, axis);
	if (block_pos.x < 0 || info->map_width < block_pos.x + 1
		|| block_pos.y < 0 || info->map_height < block_pos.y + 1)
		return (MAP_ERROR);
	return (info->map[(size_t)block_pos.y][(size_t)block_pos.x].type);
}

t_axis	get_closer_axis(t_info *info, \
	t_pos horizontal_ray, t_pos vertical_ray)
{
	if (horizontal_ray.x == 0 && horizontal_ray.y == 0)
		return (VERTICAL);
	else if (vertical_ray.x == 0 && vertical_ray.y == 0)
		return (HORIZONTAL);
	else if (fabs(horizontal_ray.x - info->player.x)
		< fabs(vertical_ray.x - info->player.x))
		return (HORIZONTAL);
	else
		return (VERTICAL);
}

double	calculate_distance(t_pos pos1, t_pos pos2)
{
	double	distance;

	distance = sqrt(pow(pos2.x - pos1.x, 2) \
		+ pow(pos2.y - pos1.y, 2));
	return (distance);
}

int	calculate_img_col(t_info *info, t_direction direction, t_pos pos)
{
	if (direction == NORTH)
		return ((floor(pos.x + 1) - pos.x) * (info->north_xpm_img.width - 1));
	else if (direction == SOUTH)
		return ((pos.x - floor(pos.x)) * (info->south_xpm_img.width - 1));
	else if (direction == WEST)
		return ((pos.y - floor(pos.y)) * (info->west_xpm_img.width - 1));
	else
		return ((floor(pos.y + 1) - pos.y) * (info->east_xpm_img.width - 1));
}
