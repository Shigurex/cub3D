/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 00:53:49 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/10 02:31:45 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP_H
# define SETUP_H

# include	<stdlib.h>
# include	<math.h>
# include	"define.h"
# include	"parse.h"
# include	"plot.h"

# define ROTATE_SPEED 4
# define ROTATE_SPEED_MOUSE 0.1
# define SPEED 0.1
# define FAST_SPEED 0.2

# define MOUSE_MOVE_MAX 300
# define MOUSE_MOVE_MIN 10

# define HORIZONTAL_SIGHT_ANGLE 60
# define VERTICAL_SIGHT_ANGLE 50

# define HEIGHT 0.3

# define ESC 53

# define SHIFT 257

# define SPACE 49

# define LEFT 123
# define RIGHT 124

# define W 13
# define A 0
# define S 1
# define D 2

# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_MOUSEDOWN 4
# define ON_MOUSEUP 5
# define ON_MOUSEMOVE 6
# define ON_EXPOSE 12
# define ON_DESTROY 17

typedef enum e_key_flag
{
	CLEAR_ALL = 0,
	MOVE = 1111 << 0,
	MOVE_FORWARD = 1 << 0,
	MOVE_BACKWORD = 1 << 1,
	MOVE_LEFT = 1 << 2,
	MOVE_RIGHT = 1 << 3,
	ROTATE_LEFT = 1 << 4,
	ROTATE_RIGHT = 1 << 5,
	SPEED_UP = 1 << 6
}	t_key_flag;

/* setup.c */
void	init_setup(t_info *info);
int		close_window(t_info *info);

/* key.c */
int		handle_key_press_action(int keycode, t_info *info);
int		handle_key_release_action(int keycode, t_info *info);

#endif
