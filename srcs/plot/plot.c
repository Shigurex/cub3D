/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:47:27 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/09 21:24:46 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"plot.h"

int	plot_screen(t_info *info)
{
	move_view(info);
	move_direction(info);
	plot_view(info);
	plot_minimap(info);
	return (0);
}
