/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 00:21:22 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/09 01:01:09 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"setup.h"

int	handle_key_press_action(int keycode, t_info *info)
{
	if (keycode == ESC)
		close_window(info);
	else if (keycode == LEFT)
		info->key_flag |= ROTATE_LEFT;
	else if (keycode == RIGHT)
		info->key_flag |= ROTATE_RIGHT;
	else if (keycode == W)
		info->key_flag |= MOVE_FORWARD;
	else if (keycode == A)
		info->key_flag |= MOVE_LEFT;
	else if (keycode == S)
		info->key_flag |= MOVE_BACKWORD;
	else if (keycode == D)
		info->key_flag |= MOVE_RIGHT;
	return (0);
}

int	handle_key_release_action(int keycode, t_info *info)
{
	(void)info;
	if (keycode == LEFT)
		info->key_flag &= ~ROTATE_LEFT;
	else if (keycode == RIGHT)
		info->key_flag &= ~ROTATE_RIGHT;
	else if (keycode == W)
		info->key_flag &= ~MOVE_FORWARD;
	else if (keycode == A)
		info->key_flag &= ~MOVE_LEFT;
	else if (keycode == S)
		info->key_flag &= ~MOVE_BACKWORD;
	else if (keycode == D)
		info->key_flag &= ~MOVE_RIGHT;
	return (0);
}
