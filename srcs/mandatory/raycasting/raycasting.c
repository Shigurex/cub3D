/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:44:58 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/09 16:01:01 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../../includes/raycasting.h"

t_pos	find_block_pos(t_pos intersection, double angle, int direction)
{
	t_pos	block;

	if (direction == HORIZONTAL && 0 <= angle && angle < M_PI)
	{
		block.x = floor(intersection.x);
		block.y = round(intersection.y);
	}
	else if (direction == HORIZONTAL && M_PI <= angle && angle < 2 * M_PI)
	{
		block.x = floor(intersection.x);
		block.y = round(intersection.y - 1);
	}
	else if (direction == VERTICAL && ((0 <= angle && angle < M_PI_2)
			|| (3 * M_PI_2 <= angle && angle < 2 * M_PI)))
	{
		block.x = round(intersection.x);
		block.y = floor(intersection.y);
	}
	else
	{
		block.x = round(intersection.x - 1);
		block.y = floor(intersection.y);
	}
	return (block);
}

int	check_block(t_pos intersection, double angle, int direction)
{
	int	block;

	if (intersection.x < 0 || intersection.y < 0)
		return (MAP_ERROR);
	intersection = find_block_pos(intersection, angle, direction);
	block = map(intersection.x, intersection.y, NULL);
	return (block);
}

int	get_sign(double angle, int direction)
{
	if (direction == HORIZONTAL && 0 <= angle && angle < M_PI)
		return (1);
	else if (direction == HORIZONTAL && M_PI <= angle && angle < 2 * M_PI)
		return (-1);
	else if (direction == VERTICAL && ((0 <= angle && angle < M_PI_2)
			|| (3 * M_PI_2 <= angle && angle < 2 * M_PI)))
		return (1);
	else
		return (-1);
}

t_pos	check_horizontal_intersection(t_info *info, double angle)
{
	t_pos	ray;
	double	dy;
	int		block;
	int		sign;

	if (M_PI <= angle && angle < M_PI * 2)
		dy = floor(info->player.y) - info->player.y;
	else
		dy = ceil(info->player.y) - info->player.y;
	sign = get_sign(angle, HORIZONTAL);
	ray.x = info->player.x + dy / tan(angle);
	ray.y = info->player.y + dy;
	while (true)
	{
		block = check_block(ray, angle, HORIZONTAL);
		if (block == BLOCK || block == NONE || block == MAP_ERROR) //function
			break ;
		ray.x = ray.x + sign * 1 / tan(angle);
		ray.y = ray.y + sign;
	}
	return (ray);
}

t_pos	check_vertical_intersection(t_info *info, double angle)
{
	t_pos	ray;
	double	dx;
	int		block;
	int		sign;

	if (M_PI_2 <= angle && angle < M_PI_2 * 3)
		dx = floor(info->player.x) - info->player.x;
	else
		dx = ceil(info->player.x) - info->player.x;
	sign = get_sign(angle, VERTICAL);
	ray.x = info->player.x + dx;
	ray.y = info->player.y + dx * tan(angle);
	while (true)
	{
		block = check_block(ray, angle, VERTICAL);
		if (block == BLOCK || block == NONE || block == MAP_ERROR) //function
			break ;
		ray.x = ray.x + sign;
		ray.y = ray.y + sign * tan(angle);
	}
	return (ray);
}

double	calculate_distance(t_pos player, t_pos wall)
{
	double	distance;

	distance = sqrt(pow(wall.x - player.x, 2) + pow(wall.y - player.y, 2));
	return (distance);
}

t_pos	check_intersection(t_info *info, double angle)
{
	t_pos	horizontal_intersection;
	t_pos	vertical_intersection;

	horizontal_intersection = check_horizontal_intersection(info, angle);
	vertical_intersection = check_vertical_intersection(info, angle);
	printf("horizontal: (x, y) = (%f, %f)\n", horizontal_intersection.x, horizontal_intersection.y);
	printf("vertical: (x, y) = (%f, %f)\n", vertical_intersection.x, vertical_intersection.y);
	if (fabs(horizontal_intersection.x - info->player.x)
		< fabs(vertical_intersection.x - info->player.x))
		return (horizontal_intersection);
	else
		return (vertical_intersection);
}

//int	main(void)
//{
//	t_info	info;

//	info.player.x = 4.3;
//	info.player.y = 4.3;
//	//check_intersection(&info, get_radian_from_degree(145));
//	check_horizontal_intersection(&info, get_radian_from_degree(30));
//	//check_vertical_intersection(&info, get_radian_from_degree(40));
//	return (0);
//}
