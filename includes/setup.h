/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 00:53:49 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/09 02:43:43 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP_H
# define SETUP_H

# include	<stdlib.h>
# include	"define.h"
# include	"parse.h"
# include	"plot.h"

# define ROTATE_SPEED 0.01
# define SPEED 0.01

# define SIGHT_ANGLE 60

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

typedef enum e_key_flag
{
	MOVE_FORWARD = 1 << 0,
	MOVE_BACKWORD = 1 << 1,
	MOVE_LEFT = 1 << 2,
	MOVE_RIGHT = 1 << 3,
	ROTATE_LEFT = 1 << 4,
	ROTATE_RIGHT = 1 << 5
}	t_key_flag;

/* setup.c */
void	init_setup(t_info *info);
int		close_window(t_info *info);

/* key.c */
int		handle_key_press_action(int keycode, t_info *info);
int		handle_key_release_action(int keycode, t_info *info);

#endif
