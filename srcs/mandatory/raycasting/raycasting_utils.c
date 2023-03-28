/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:38:00 by yahokari          #+#    #+#             */
/*   Updated: 2023/03/28 16:38:08 by yahokari         ###   ########.fr       */
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
