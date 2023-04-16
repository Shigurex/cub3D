/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arms.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 18:00:11 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/16 18:23:26 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"plot.h"

void	plot_arms(t_info *info)
{
	static size_t	i = 0;
	static size_t	j = 0;

	mlx_put_image_to_window(info->mlx, info->win, \
		info->textures.arms[i % ARMS].address, 0, 0);
	mlx_put_image_to_window(info->mlx, info->win, \
		info->textures.arms[5 - (i % ARMS)].address, 0, 0);
	if (info->keys & MOVE)
		j++;
	if (j % 8 == 7)
	{
		i++;
		j = 0;
	}
}
