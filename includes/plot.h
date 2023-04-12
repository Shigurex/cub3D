/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:06:31 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/10 21:11:39 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLOT_H
# define PLOT_H
#include "debug.h"//------------------------test

# include	<math.h>
# include	<float.h>
# include	"define.h"
# include	"utils.h"
# include	"raycasting.h"

/* plot.h */
int				plot_screen(t_info *info);

/* base.c */
void			plot_base(t_info *info);

/* minimap.h */
void			plot_minimap(t_info *info);

/* action.c */
void			move_view(t_info *info);
void			move_direction(t_info *info);

/* pixel_put.c */
void			my_pixel_put(t_img *img, int x, int y, unsigned int color);
unsigned int	my_pixel_get(t_img *img, int x, int y);

#endif
