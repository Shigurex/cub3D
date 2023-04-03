/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:56:58 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/03 12:17:44 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include	"../minilibx-linux/mlx.h"
# include	"utils.h"

# define WIN_WIDTH 1200
# define WIN_HEIGHT 900

# define FILE_EXTENSION ".cub"

typedef struct s_img
{
	void	*address;
	char	*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_texture
{
	void	*data;
	int		width;
	int		height;
}	t_texture;

typedef struct s_info
{
	void			*mlx;
	void			*win;
	t_img			img;
	t_circ_list		*map_list;
	t_texture		north_texture;
	t_texture		south_texture;
	t_texture		west_texture;
	t_texture		east_texture;
	unsigned int	floor_color;
	unsigned int	ceiling_color;
}	t_info;

#endif
