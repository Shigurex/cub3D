/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:47:27 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/07 15:48:49 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"plot.h"

void	plot_screen(t_info *info)
{
	mlx_put_image_to_window(info->mlx, info->win, \
		info->minimap.address, 20, 20);
}
