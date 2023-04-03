/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 00:21:22 by yahokari          #+#    #+#             */
/*   Updated: 2023/03/31 00:21:33 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"setup.h"

int	handle_key_input(int keycode, t_info *info)
{
	if (keycode == ESC)
		close_window(info);
	else if (keycode == LEFT || keycode == RIGHT)
		;
	else if (keycode == W || keycode == A || keycode == S || keycode == D)
		;
	return (0);
}
