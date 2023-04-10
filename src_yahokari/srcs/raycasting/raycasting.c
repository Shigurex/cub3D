/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:36:13 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/10 10:39:39 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"raycasting.h"

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
		block = get_bumped_block(info, ray, angle, HORIZONTAL);
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
		block = get_bumped_block(info, ray, angle, VERTICAL);
		if (block == WALL || block == NONE || block == MAP_ERROR)
			break ;
		ray = assign_pos(ray.x + sign, ray.y + sign * tan(angle));
	}
	return (ray);
}

static t_direction	get_wall_direction(double angle, t_axis axis)
{
	if (axis == HORIZONTAL && (0 < angle && angle < M_PI))
		return (NORTH);
	else if (axis == HORIZONTAL && (M_PI < angle && angle < 2 * M_PI))
		return (SOUTH);
	else if (axis == VERTICAL && ((0 <= angle && angle < M_PI_2) \
		|| (3 * M_PI_2 < angle && angle < 2 * M_PI)))
		return (WEST);
	else
		return (EAST);
}

static t_xpm_img	get_wall_img(t_info *info, t_direction direction)
{
	if (direction == NORTH)
		return (info->north_xpm_img);
	else if (direction == SOUTH)
		return (info->south_xpm_img);
	else if (direction == WEST)
		return (info->west_xpm_img);
	else
		return (info->east_xpm_img);
}

t_intersection	check_intersection(t_info *info, double angle)
{
	t_pos			horizontal_ray;
	t_pos			vertical_ray;
	t_intersection	intersection;

	horizontal_ray = check_horizontal_intersection(info, angle);
	vertical_ray = check_vertical_intersection(info, angle);
	intersection.axis = get_closer_axis(info, horizontal_ray, vertical_ray);
	if (intersection.axis == VERTICAL)
		intersection.pos = vertical_ray;
	else if (intersection.axis == HORIZONTAL)
		intersection.pos = horizontal_ray;
	intersection.type = get_bumped_block(info, \
		intersection.pos, angle, intersection.axis);
	intersection.distance = calculate_distance(info->player, intersection.pos);
	intersection.distance_plot = (intersection.pos.x - info->player.x) * cos(degree_to_radian(info->direction) - angle) + (intersection.pos.y - info->player.y) * sin(degree_to_radian(info->direction) - angle);
	intersection.direction = get_wall_direction(angle, intersection.axis);
	intersection.xpm_img = get_wall_img(info, intersection.direction);
	intersection.xpm_img_col = calculate_img_col(info, \
		intersection.direction, intersection.pos);
	return (intersection);
}
