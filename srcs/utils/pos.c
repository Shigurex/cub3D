/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:15:27 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/10 18:14:40 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"utils.h"

t_pos	assign_pos(double x, double y)
{
	t_pos	pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}

double	calculate_distance(t_pos pos1, t_pos pos2)
{
	double	distance;

	distance = sqrt(pow(pos2.x - pos1.x, 2) \
		+ pow(pos2.y - pos1.y, 2));
	return (distance);
}
