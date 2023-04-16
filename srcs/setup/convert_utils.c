/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:32:22 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/15 23:40:03 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"setup.h"

void	allocate_map_info(t_info *info)
{
	size_t	i;

	info->map = malloc(sizeof(t_block *) * info->map_height);
	if (!info->map)
		exit_with_message("failed to allocate memory");
	i = 0;
	while (i < info->map_height)
	{
		info->map[i] = malloc(sizeof(t_block) * info->map_width);
		if (!info->map[i])
			exit_with_message("failed to allocate memory");
		i++;
	}
}

void	clear_map(t_info *info)
{
	t_block	**map;
	size_t	i;

	map = info->map;
	i = 0;
	while (i < info->map_height)
	{
		free(map[i]);
		i++;
	}
	free(map);
	info->map = NULL;
}
