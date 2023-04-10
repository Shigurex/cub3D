/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:32:22 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/10 17:30:00 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"setup.h"

void	allocate_map_info(t_info *info)
{
	size_t	i;

	if (info->enemy_num > 0)
	{
		info->enemy = malloc(sizeof(t_character) * info->enemy_num);
		if (!info->enemy)
			exit_with_message("failed to allocate memory");
	}
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
