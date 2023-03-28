/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mk_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:50:56 by yahokari          #+#    #+#             */
/*   Updated: 2023/03/28 16:51:05 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/setting.h"

int	check_map_shape(unsigned char *map, size_t x, size_t y)
{
	size_t	i;

	i = 0;
	while (i < x * y)
	{
		if (map[i] == SPACE \
		&& (!(i / x) || !(i % x) || i / x == y - 1 || i % x == x - 1 \
			|| map[i + 1] == NONE || map[i - 1] == NONE \
			|| map[i + x] == NONE || map[i - x] == NONE))
			return (1);
		i++;
	}
	return (0);
}
