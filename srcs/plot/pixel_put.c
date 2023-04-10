/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 01:01:24 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/04 17:40:02 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"plot.h"

void	my_pixel_put(t_img *img, int x, int y, unsigned int color)
{
	void	*dst;

	dst = img->data + (y * img->size_l + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}
