/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:49:04 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/16 21:50:53 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"raycasting.h"

static t_ray	check_horizontal_intersection(t_info *info, double angle)
{
	t_ray	ray;
	t_block	block;
	int		sign;
	double	dy;

	ray.pos = assign_pos(0, 0);
	if (0 < angle && angle < M_PI)
		dy = ceil(info->player.pos.y) - info->player.pos.y;
	else if (M_PI < angle && angle < 2 * M_PI)
		dy = floor(info->player.pos.y) - info->player.pos.y;
	else
		return (ray);
	sign = get_sign(dy);
	ray.pos = assign_pos(info->player.pos.x + dy / tan(angle), \
		info->player.pos.y + dy);
	while (true)
	{
		block = get_bumped_block(info, ray.pos, angle, HORIZONTAL);
		ray.type = block.type;
		if (block.type == WALL || block.type == NONE || block.type == MAP_ERROR
			|| (block.type == DOOR && is_door_hit(info, &ray, block)))
			break ;
		ray.pos = assign_pos(ray.pos.x + sign * 1 / tan(angle), ray.pos.y + sign);
	}
	return (ray);
}

static t_ray	check_vertical_intersection(t_info *info, double angle)
{
	t_ray	ray;
	t_block	block;
	int		sign;
	double	dx;

	ray.pos = assign_pos(0, 0);
	if ((0 <= angle && angle < M_PI_2)
		|| (3 * M_PI_2 < angle && angle < 2 * M_PI))
		dx = ceil(info->player.pos.x) - info->player.pos.x;
	else if (M_PI_2 < angle && angle < 3 * M_PI_2)
		dx = floor(info->player.pos.x) - info->player.pos.x;
	else
		return (ray);
	sign = get_sign(dx);
	ray.pos = assign_pos(info->player.pos.x + dx, \
		info->player.pos.y + dx * tan(angle));
	while (true)
	{
		block = get_bumped_block(info, ray.pos, angle, VERTICAL);
		ray.type = block.type;
		if (block.type == WALL || block.type == NONE || block.type == MAP_ERROR
			|| (block.type == DOOR && is_door_hit(info, &ray, block)))
			break ;
		ray.pos = assign_pos(ray.pos.x + sign, ray.pos.y + sign * tan(angle));
	}
	return (ray);
}

static int	calculate_img_col(t_img img, t_direction direction, t_pos pos)
{
	if (direction == NORTH)
		return ((floor(pos.x + 1) - pos.x) * (img.width - 1));
	else if (direction == SOUTH)
		return ((pos.x - floor(pos.x)) * (img.width - 1));
	else if (direction == WEST)
		return ((pos.y - floor(pos.y)) * (img.width - 1));
	else
		return ((floor(pos.y + 1) - pos.y) * (img.width - 1));
}

t_ray	check_intersection(t_info *info, double angle)
{
	t_ray	ray;
	t_ray	horizontal_ray;
	t_ray	vertical_ray;
	double	angle_radian;

	angle_radian = degree_to_radian(angle);
	horizontal_ray = check_horizontal_intersection(info, angle_radian);
	vertical_ray = check_vertical_intersection(info, angle_radian);
	ray.axis = get_closer_axis(info, horizontal_ray.pos, vertical_ray.pos);
	if (ray.axis == VERTICAL)
	{
		ray.pos = vertical_ray.pos;
		ray.type = vertical_ray.type;
	}
	else if (ray.axis == HORIZONTAL)
	{
		ray.pos = horizontal_ray.pos;
		ray.type = horizontal_ray.type;
	}
	ray.distance = calculate_distance(info->player.pos, ray.pos);
	ray.yaw = angle;
	ray.direction = get_wall_direction(angle_radian, ray.axis);
	if (ray.type == DOOR)
		ray.img = info->textures.door;
	else
		ray.img = get_wall_img(info, ray.direction);
	ray.img_col = calculate_img_col(ray.img, ray.direction, ray.pos);
	return (ray);
}
