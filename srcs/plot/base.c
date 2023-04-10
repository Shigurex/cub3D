/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:34:04 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/10 20:05:42 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"plot.h"

static void	plot_line(t_info *info, t_ray ray)
{
	int	i;

	i = 0;
	while (i < WIN_HEIGHT)
	{
		
		i++;
	}
}

void	plot_base(t_info *info)
{
	int		i;
	t_ray	ray;
	double	angle;

	i = 0;
	while (i < WIN_WIDTH)
	{
		angle = info->player.yaw + \
			((double)i - WIN_WIDTH / 2) / WIN_WIDTH * SIGHT_YAW;
		ray = check_intersection(info, angle);
		plot_line(info, ray);
		printf("%f\n", angle);
		i++;
	}
}
