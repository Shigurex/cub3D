/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:56:58 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/08 18:29:59 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include	<stdio.h>
# include	"../minilibx-linux/mlx.h"

# define WIN_WIDTH 1200
# define WIN_HEIGHT 900

# define MINIMAP_WIDTH 200
# define MINIMAP_HEIGHT 200

# define MINIMAP_SIZE 8

# define FILE_EXTENSION ".cub"

typedef enum e_type
{
	SPACE,
	WALL,
	DOOR,
	NONE,
	MAP_ERROR
}	t_type;

typedef enum e_direction
{
	NORTH = 270,
	SOUTH = 90,
	WEST = 180,
	EAST = 0
}	t_direction;

typedef enum e_axis
{
	VERTICAL,
	HORIZONTAL
}	t_axis;

typedef struct s_circ_list
{
	char				*str;
	struct s_circ_list	*next;
	struct s_circ_list	*prev;
}	t_circ_list;

typedef struct s_img
{
	void	*address;
	char	*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_xpm_img
{
	void	*address;
	int		width;
	int		height;
}	t_xpm_img;

typedef struct s_pos
{
	double	x;
	double	y;
}	t_pos;

typedef struct s_intersection
{
	t_type	type;
	t_axis	axis;
	t_pos	pos;
	double	distance;
}	t_intersection;

typedef struct s_block
{
	t_type	type;
	t_pos	begin;
	t_pos	end;
}	t_block;

typedef struct s_info
{
	void			*mlx;
	void			*win;
	t_img			img;
	t_img			minimap;
	t_pos			player;
	double			direction;
	t_block			**map;
	t_circ_list		*map_list;
	size_t			map_width;
	size_t			map_height;
	t_xpm_img		north_xpm_img;
	t_xpm_img		south_xpm_img;
	t_xpm_img		west_xpm_img;
	t_xpm_img		east_xpm_img;
	unsigned int	floor_color;
	unsigned int	ceiling_color;
	unsigned int	key_flag;
}	t_info;

#endif
