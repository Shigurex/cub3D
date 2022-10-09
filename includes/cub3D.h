/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:45:04 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/09 20:50:48 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include	<stdlib.h>
# include	<stdio.h>
# include	<fcntl.h>
# include	<unistd.h>
# include	"../mlx-linux/mlx.h"
# include	"structure.h"
# include	"setting.h"
# include	"global.h"
# include	"raycasting.h"

# define ON_KEYDOWN 2
# define ON_DESTROY 17

int	close_window(t_info *info);
int	handle_key_input(int keycode, t_info *info);

#endif
