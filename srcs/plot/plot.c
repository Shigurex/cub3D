/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:07:04 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/17 00:08:33 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"plot.h"

int	plot_screen(t_info *info)
{
	if (!(info->keys & START))
		return (mlx_put_image_to_window(info->mlx, info->win, \
		info->textures.start.address, 0, 0) * 0 + 1);
	move_view(info);
	move_direction(info);
	plot_base(info);
	plot_arms(info);
	plot_minimap(info);
	return (0);
}
