/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 00:21:22 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/08 19:43:25 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"setup.h"

//static void	move_view(t_info *info, int keycode)
//{
//	if (keycode == LEFT)
//		info->direction -= ROT_SPEED;
//	else if (keycode == RIGHT)
//		info->direction += ROT_SPEED;
//}

//static void	move_forward()
//{
//	;
//}

int	handle_key_press_action(int keycode, t_info *info)
{
	printf("%s, %d\n", __FILE__, __LINE__);
	if (keycode == ESC)
		close_window(info);
	else if (keycode == LEFT)
		;
		//info->key_flag |= ROTATE_LEFT;
	//else if (keycode == LEFT || keycode == RIGHT)
	//	;
	//else if (keycode == W || keycode == A || keycode == S || keycode == D)
	//	;
	return (0);
}

int	handle_key_release_action(int keycode, t_info *info)
{
	(void)info;
	printf("%s, %d\n", __FILE__, __LINE__);
	if (keycode == LEFT)
		;
		//info->key_flag &= ~ROTATE_LEFT;
	if (keycode == LEFT || keycode == RIGHT)
		;
	else if (keycode == W || keycode == A || keycode == S || keycode == D)
		;
	return (0);
}
