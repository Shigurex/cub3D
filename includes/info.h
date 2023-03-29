/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:56:58 by yahokari          #+#    #+#             */
/*   Updated: 2023/03/29 23:01:21 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include	"../minilibx-linux/mlx.h"

# define DIS_X 1200
# define DIS_Y 900

typedef struct s_img {
	void	*address;
	char	*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_info
{
	void	*mlx;
	void	*win;
	t_img	img;
}	t_info;

#endif
