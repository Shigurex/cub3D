/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 10:46:24 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/10 12:02:28 by yahokari         ###   ########.fr       */
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

/* key hook */
# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_MOUSEDOWN 4
# define ON_MOUSEUP 5
# define ON_MOUSEMOVE 6
# define ON_EXPOSE 12
# define ON_DESTROY 17

# define ENERMY_IMGS 8

typedef enum e_type
{
	WALL,
	DOOR,
	SPACE,
	NONE,
	MAP_ERROR
}	t_type;

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
	t_img			enermy[ENERMY_IMGS];
}	t_texture;

typedef struct s_screen
{
	t_img		base;
	t_img		enermy;
	t_img		minimap;
}	t_screen;

typedef struct s_pos
{
	double	x;
	double	y;
}	t_pos;

typedef struct s_character
{
	bool	is_alive;
	t_pos	pos;
	double	yaw; //横(mapとかの表示用)
	double	pitch; //縦(視野の上下用)
	size_t	time;
}	t_character;

typedef struct s_block
{
	t_type	type;
}	t_block;

typedef struct s_info
{
	void			*mlx;
	void			*win;
	t_texture		textures;
	t_screen		screens;
	t_block			**map;
	t_character		player;
	t_character		*enermy;
	unsigned int	keys;
}	t_info;

#endif
