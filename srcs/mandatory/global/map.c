/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 03:36:38 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/10 03:38:30 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../../includes/global.h"

int	map(size_t x, size_t y, char *file)
{
	static unsigned char	*cube_map;
	static size_t			X;
	static size_t			Y;

	if (file)
		cube_map = mk_map(file, &X, &Y);
	else if (file == FREE_CONTENT)
	{
		free(cube_map);
		return (MAP_ERROR);
	}
	if (x >= X || y >= Y || !cube_map)
		return (MAP_ERROR);
	return (cube_map[(y * X) + x]);
}
