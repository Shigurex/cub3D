/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 00:53:49 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/08 19:07:48 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP_H
# define SETUP_H

# include	<stdlib.h>
# include	"define.h"
# include	"parse.h"
# include	"plot.h"

# define MOVE_FORWARD 0b1
# define MOVE_BACKWORD 0b10
# define MOVE_LEFT 0b100
# define MOVE_RIGHT 0b1000
# define ROTATE_LEFT 0b10000
# define ROTATE_RIGHT 0b100000

# define ROTATE_SPEED 0.5
# define SPEED 0.01

# define ESC 65307

# define LEFT 65361
# define RIGHT 65363

# define W 119
# define A 97
# define S 115
# define D 100

# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_MOUSEDOWN 4
# define ON_MOUSEUP 5
# define ON_MOUSEMOVE 6
# define ON_EXPOSE 12
# define ON_DESTROY 17

/* setup.c */
void	init_setup(t_info *info);
int		close_window(t_info *info);

/* key.c */
int		handle_key_press_action(int keycode, t_info *info);
int		handle_key_release_action(int keycode, t_info *info);

#endif
