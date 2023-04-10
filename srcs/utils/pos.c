/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:15:27 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/10 16:15:54 by yahokari         ###   ########.fr       */
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
