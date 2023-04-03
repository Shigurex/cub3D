/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:26:40 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/03 12:24:34 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"parse.h"

void	input_color(t_info *info, char **split_line)
{
	//char	**colors;

	if (!strcmp(split_line[0], "F"))
		info->floor_color = rgb_to_color(0, 0, 0);
	else if (!strcmp(split_line[0], "C"))
		info->ceiling_color = rgb_to_color(0, 0, 0);
	//colors = ft_split(split_line[1], ',');
	//if (count_split_size(colors) != 3)
	//	exit_with_message("invalid format for contents set at the map");
	//printf("%s, %d\n", __FILE__, __LINE__);
	//safe_free_char_double_pointer(&colors);
}
