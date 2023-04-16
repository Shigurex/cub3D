/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:29:28 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/17 00:04:09 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"setup.h"

int	handle_key_press_action(int keycode, t_info *info)
{
	if (keycode == KEY_ESC)
		close_window(info);
	else if (keycode == KEY_LEFT)
		info->keys |= ROTATE_LEFT;
	else if (keycode == KEY_RIGHT)
		info->keys |= ROTATE_RIGHT;
	else if (keycode == KEY_W)
		info->keys |= MOVE_FORWARD;
	else if (keycode == KEY_A)
		info->keys |= MOVE_LEFT;
	else if (keycode == KEY_S)
		info->keys |= MOVE_BACKWARD;
	else if (keycode == KEY_D)
		info->keys |= MOVE_RIGHT;
	else if (keycode == KEY_ENTER)
		info->keys |= START;
	return (0);
}

int	handle_key_release_action(int keycode, t_info *info)
{
	if (keycode == KEY_LEFT)
		info->keys &= ~ROTATE_LEFT;
	else if (keycode == KEY_RIGHT)
		info->keys &= ~ROTATE_RIGHT;
	else if (keycode == KEY_W)
		info->keys &= ~MOVE_FORWARD;
	else if (keycode == KEY_A)
		info->keys &= ~MOVE_LEFT;
	else if (keycode == KEY_S)
		info->keys &= ~MOVE_BACKWARD;
	else if (keycode == KEY_D)
		info->keys &= ~MOVE_RIGHT;
	return (0);
}
