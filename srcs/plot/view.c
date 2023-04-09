/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 02:28:35 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/09 17:36:56 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"plot.h"

void	plot_view(t_info *info)
{
	size_t			i;
	// double			angle;
	// t_intersection	intersecion;

	(void)info;
	i = 0;
	while (i < WIN_WIDTH)
	{
		// angle = info->direction + \
		// 	((double)i - WIN_WIDTH / 2) / WIN_WIDTH * SIGHT_ANGLE;
		// intersecion = check_intersection(info, angle);
		i++;
	}
	//mlx_put_image_to_window(info->mlx, info->win, info->img.address, 0, 0);
}
