/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 01:01:24 by yahokari          #+#    #+#             */
/*   Updated: 2023/03/30 01:01:33 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"utils.h"

void	my_pixel_put(t_info *info, int x, int y, unsigned int color)
{
	void	*dst;

	dst = info->img.data + (y * info->img.size_l + x * (info->img.bpp / 8));
	*(unsigned int *)dst = color;
}
