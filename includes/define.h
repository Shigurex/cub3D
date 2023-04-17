/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 10:46:24 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/17 00:09:25 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include	<stdio.h>
# include	<stdbool.h>
# include	"../minilibx_mms_20200219/mlx.h"
# include	"../libft/libft.h"

/* window */
# define WIN_WIDTH 1200
# define WIN_HEIGHT 900

/* minimap */
# define MINIMAP_WIDTH 200
# define MINIMAP_HEIGHT MINIMAP_WIDTH
# define MINIMAP_SIZE 8

/* setting */
# define ROTATE_SPEED 5
# define SPEED 0.05
# define SIGHT_YAW 60
# define SIGHT_PITCH 40
# define MAX_MOUSE_MOVE 100
# define MIN_MOUSE_MOVE 3
# define ARMS 6

/* parse */
# define FILE_EXTENSION ".cub"
# define OPEN_ERR -1

/* enermy */
# define ENERMY_IMGS 8
# define ENEMY_FIND_TIME 0x400
# define ENEMY_FIRE_TIME 0x200
# define ENEMY_FIND_LEN 16
# define ENEMY_IMG_HEIGHT 300

/* key value */
# define KEY_ESC 53
# define KEY_SHIFT 257
# define KEY_SPACE 49
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ENTER 36

/* key hook */
# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_MOUSEDOWN 4
# define ON_MOUSEUP 5
# define ON_MOUSEMOVE 6
# define ON_EXPOSE 12
# define ON_DESTROY 17

typedef enum e_type
{
	WALL,
	DOOR,
	SPACE,
	NONE,
	MAP_ERROR
}	t_type;

typedef enum e_axis
{
	HORIZONTAL,
	VERTICAL
}	t_axis;

typedef enum e_arm
{
	RIGHT_ARM_1 = 0,
	RIGHT_ARM_2 = 1,
	RIGHT_ARM_3 = 2,
	LEFT_ARM_1 = 3,
	LEFT_ARM_2 = 4,
	LEFT_ARM_3 = 5,
}	t_arm;

typedef enum e_direction
{
	EAST = 0,
	NORTH_EAST = 45,
	NORTH = 90,
	NORTH_WEST = 135,
	WEST = 180,
	SOUTH_WEST = 225,
	SOUTH = 270,
	SOUTH_EAST = 315
}	t_direction;

typedef enum e_color
{
	BLACK = 0x00000000,
	TRANSPARENT = 0xFF000000,
	WHITE = 0x00FFFFFF,
	RED = 0x00FF0000,
	GREEN = 0x0000FF00,
	BLUE = 0x000000FF,
	GRAY = 0x00808080,
	SILVER = 0x00C0C0C0,
}	t_color;

typedef enum e_key_action
{
	CLEAR_ALL = 0,
	MOVE = 0b1111 << 0,
	MOVE_FORWARD = 1 << 0,
	MOVE_BACKWARD = 1 << 1,
	MOVE_LEFT = 1 << 2,
	MOVE_RIGHT = 1 << 3,
	ROTATE_LEFT = 1 << 4,
	ROTATE_RIGHT = 1 << 5,
	START = 1 << 6,
}	t_key_action;

typedef struct s_circ_list
{
	char				*str;
	struct s_circ_list	*next;
	struct s_circ_list	*prev;
}	t_circ_list;

typedef struct s_img
{
	void	*address;
	int		width;
	int		height;
	char	*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_texture
{
	t_img			north;
	t_img			south;
	t_img			west;
	t_img			east;
	unsigned int	ceiling;
	unsigned int	floor;
	t_img			door;
	t_img			arms[ARMS];
	t_img			start;
}	t_texture;

typedef struct s_screen
{
	t_img		base;
	t_img		minimap;
}	t_screen;

typedef struct s_pos
{
	double	x;
	double	y;
}	t_pos;

typedef struct s_character
{
	t_pos	pos;
	double	yaw;
	double	pitch;
	size_t	time;
}	t_character;

typedef struct s_block
{
	t_type	type;
	t_pos	door_begin;
	t_pos	door_end;
}	t_block;

typedef struct s_ray
{
	t_type		type;
	t_img		img;
	int			img_col;
	t_axis		axis;
	t_pos		pos;
	t_direction	direction;
	double		yaw;
	double		distance;
	int			row_win;
}	t_ray;

typedef struct s_info
{
	void			*mlx;
	void			*win;
	t_block			**map;
	size_t			map_width;
	size_t			map_height;
	t_texture		textures;
	t_screen		screens;
	t_character		player;
	unsigned int	keys;
}	t_info;

#endif
