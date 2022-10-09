/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 22:31:59 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/09 13:12:24 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../../includes/raycasting.h"

double	get_radian_from_degree(double degree)
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
