/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:28:05 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/09 20:15:52 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLOT_H
# define PLOT_H

# include	<math.h>
# include	<float.h>
# include	"utils.h"
# include	"define.h"
# include	"setup.h"
# include	"raycasting.h"

# define BLACK 0x00000000
# define WHITE 0x00FFFFFF
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define GRAY 0x00808080
# define SILVER 0x00C0C0C0
# define TRANSPARENT 0xFF000000

/* plot.h */
int		plot_screen(t_info *info);

/* action.h */
void	move_view(t_info *info);
void	move_direction(t_info *info);

/* minimap.c */
void	plot_minimap(t_info *info);

/* view.c */
void	plot_view(t_info *info);

/* pixel_put.c */
void	my_pixel_put(t_img *img, int x, int y, unsigned int color);

#endif
