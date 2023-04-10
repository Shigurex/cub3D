/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:58:00 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/10 15:04:38 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"utils.h"

bool	is_char_in_str(int c, char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (true);
		i++;
	}
	return (false);
}
