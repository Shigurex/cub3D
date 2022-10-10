/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mk_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:52:03 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/10 12:15:34 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/setting.h"

int	mk_img(void *img, unsigned int *dst)
{
	char	*d;
	int		i[3];
	size_t	x;
	size_t	y;

	d = mlx_get_data_addr(img, i + BITS_PER_PIXEL, i + SIZE_LINE, i + ENDIAN);
	x = 0;
	while (x < BL)
	{
		y = 0;
		while (y < BL)
		{
			*dst = get_pic(d, x, y, i);
			dst++;
			y++;
		}
		x++;
	}
	return (0);
}

unsigned int	get_pic(char *img, size_t x, size_t y, int *i)
{
	unsigned int	*img_i;

	img_i = (unsigned int *) \
	(img + (y * i[SIZE_LINE] + x * (i[BITS_PER_PIXEL] / 8)));
	return (*img_i);
}
