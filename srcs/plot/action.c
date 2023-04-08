/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:04:04 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/08 19:43:40 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"plot.h"

void	move_view(t_info *info)
{
	printf("%f\n", info->direction);
	if (info->key_flag & ROTATE_LEFT)
		info->direction -= ROTATE_SPEED;
	if (info->key_flag & ROTATE_RIGHT)
		info->direction += ROTATE_SPEED;
}

//void	move_direction(t_info *info)
//{
//	;
//}
