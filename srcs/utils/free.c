/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:24:39 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/10 14:27:12 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"utils.h"

void	safe_free_char_pointer(char **str)
{
	free(*str);
	*str = NULL;
}

void	safe_free_char_double_pointer(char ***str)
{
	char	**tmp;
	size_t	i;

	tmp = *str;
	i = 0;
	while (tmp[i])
	{
		safe_free_char_pointer(&tmp[i]);
		i++;
	}
	free(tmp);
	*str = NULL;
}
