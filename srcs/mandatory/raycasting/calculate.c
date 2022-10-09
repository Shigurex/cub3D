/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 22:31:59 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/09 17:35:10 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../../includes/raycasting.h"

double	convert_to_radian(double degree)
{
	double	radian;

	degree = fmod(degree, 360);
	if (degree < 0)
		degree = fmod(fmod(degree, 360) + 360, 360);
	else if (degree >= 360)
		degree = fmod(degree, 360);
	radian = degree / 360 * 2 * M_PI;
	return (radian);
}

double	calculate_distance(t_pos player, t_pos wall)
{
	double	distance;

	distance = sqrt(pow(wall.x - player.x, 2) + pow(wall.y - player.y, 2));
	return (distance);
}
