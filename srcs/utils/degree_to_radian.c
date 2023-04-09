/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   degree_to_radian.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:38:28 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/08 23:06:14 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"utils.h"

double	convert_degree_within_two_pie(double degree)
{
	degree = fmod(degree, 360);
	if (degree <= 0)
		degree = fmod(fmod(degree, 360) + 360, 360);
	return (degree);
}

double	degree_to_radian(double degree)
{
	double	radian;

	degree = convert_degree_within_two_pie(degree);
	radian = degree / 360 * 2 * M_PI;
	return (radian);
}
