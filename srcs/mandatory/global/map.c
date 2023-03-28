/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:24:14 by yahokari          #+#    #+#             */
/*   Updated: 2023/03/28 16:32:58 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/global.h"

int	map(size_t x, size_t y, char *file)
{
	static unsigned char	*cube_map;
	static size_t			width;
	static size_t			height;

	if (file)
		cube_map = mk_map(file, &width, &height);
	else if (file == FREE_CONTENT)
	{
		free(cube_map);
		return (MAP_ERROR);
	}
	if (x >= width || y >= height || !cube_map)
		return (MAP_ERROR);
	return (cube_map[(y * width) + x]);
}
