/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:51:39 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/03 12:24:58 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"parse.h"

static void	get_map_line(char *line)
{
	size_t	i;
	char	*last_not_of_valid_chars;

	i = ft_strlen(line);
	if (i == 0)
		return ;
	while (i > 0)
	{
		if (line[i] == ' ' || line[i] == '\0')
			last_not_of_valid_chars = &line[i];
		else if (line[i] == '0' || line[i] == '1' || line[i] == 'N'
			|| line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
			break ;
		else
			exit_with_message("invalid characters set in map");
		i--;
	}
	*last_not_of_valid_chars = '\0';
}

void	input_map(t_info *info, char *line)
{
	static bool	is_map_finish = false;
	char		*map_line;

	if (!info->map_list && !ft_strcmp(line, EMPTY_STRING))
		return ;
	else if (info->map_list && !ft_strcmp(line, EMPTY_STRING))
		is_map_finish = true;
	else if (is_map_finish)
		exit_with_message("information written after the map end");
	get_map_line(line);
	map_line = ft_strdup(line);
	if (!map_line)
		exit_with_message("failed to allocate memory");
	insert_list(&info->map_list, map_line);
}