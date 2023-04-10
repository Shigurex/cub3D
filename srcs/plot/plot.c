/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:07:04 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/10 19:54:41 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"plot.h"

int	plot_screen(t_info *info)
{
	move_view(info);
	move_direction(info);
	plot_base(info);
	plot_minimap(info);
	return (0);
}
