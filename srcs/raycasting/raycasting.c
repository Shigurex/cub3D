/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:36:13 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/07 19:41:46 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"raycasting.h"

static int	get_sign(double value)
{
	if (value >= 0)
		return (1);
	return (-1);
}

static t_pos	get_block_pos(t_pos ray, double angle, t_axis axis)
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

static t_type	get_block(t_info *info, t_pos ray, double angle, t_axis axis)
{
	t_pos	block_pos;

	block_pos = get_block_pos(ray, angle, axis);
	if (block_pos.x < 0 || info->map_width < block_pos.x + 1
		|| block_pos.y < 0 || info->map_height < block_pos.y + 1)
		return (MAP_ERROR);
	return (info->map[(size_t)block_pos.y][(size_t)block_pos.x].type);
}

static t_pos	check_horizontal_intersection(t_info *info, double angle)
{
	t_pos	ray;
	t_type	block;
	int		sign;
	double	dy;

	ray = assign_pos(0, 0);
	if (0 < angle && angle < M_PI)
		dy = ceil(info->player.y) - info->player.y;
	else if (M_PI < angle && angle < 2 * M_PI)
		dy = floor(info->player.y) - info->player.y;
	else
		return (ray);
	sign = get_sign(dy);
	ray = assign_pos(info->player.x + dy / tan(angle), info->player.y + dy);
	while (true)
	{
		block = get_block(info, ray, angle, HORIZONTAL);
		if (block == WALL || block == NONE || block == MAP_ERROR)
			break ;
		ray = assign_pos(ray.x + sign * 1 / tan(angle), ray.y + sign);
	}
	return (ray);
}

static t_pos	check_vertical_intersection(t_info *info, double angle)
{
	t_pos	ray;
	t_type	block;
	int		sign;
	double	dx;

	ray = assign_pos(0, 0);
	if ((0 <= angle && angle < M_PI_2)
		|| (3 * M_PI_2 < angle && angle < 2 * M_PI))
		dx = ceil(info->player.x) - info->player.x;
	else if (M_PI_2 < angle && angle < 3 * M_PI_2)
		dx = floor(info->player.x) - info->player.x;
	else
		return (ray);
	sign = get_sign(dx);
	ray = assign_pos(info->player.x + dx, info->player.y + dx * tan(angle));
	while (true)
	{
		block = get_block(info, ray, angle, VERTICAL);
		if (block == WALL || block == NONE || block == MAP_ERROR)
			break ;
		ray = assign_pos(ray.x + sign, ray.y + sign * tan(angle));
	}
	return (ray);
}

static double	calculate_distance(t_info *info, t_pos pos)
{
	double	distance;

	distance = sqrt(pow(pos.x - info->player.x, 2) \
		+ pow(pos.y - info->player.y, 2));
	return (distance);
}

static t_axis	get_axis(t_info *info, t_pos horizontal_ray, t_pos vertical_ray)
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

t_intersection	check_intersection(t_info *info, double angle)
{
	t_pos			horizontal_ray;
	t_pos			vertical_ray;
	t_intersection	intersection;

	horizontal_ray = check_horizontal_intersection(info, angle);
	vertical_ray = check_vertical_intersection(info, angle);
	intersection.axis = get_axis(info, horizontal_ray, vertical_ray);
	if (intersection.axis == VERTICAL)
		intersection.pos = vertical_ray;
	else if (intersection.axis == HORIZONTAL)
		intersection.pos = horizontal_ray;
	intersection.type = get_block(info, intersection.pos, angle, intersection.axis);
	intersection.distance = calculate_distance(info, intersection.pos);
	return (intersection);
}
