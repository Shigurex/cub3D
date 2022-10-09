/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:45:04 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/09 16:58:37 by yahokari         ###   ########.fr       */
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
# include	"map.h"
# include	"raycasting.h"

# define BL 30
# define DIS_X 1200
# define DIS_Y 900

# define MINI_MAP 300
# define MINI_MAP_BL 30

# define ON_KEYDOWN 2
# define ON_DESTROY 17

int	close_window(t_info *info);
int	handle_key_input(int keycode, t_info *info);

#endif
