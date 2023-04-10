/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:06:31 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/10 17:13:46 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLOT_H
# define PLOT_H

# include	<math.h>
# include	"define.h"
# include	"utils.h"

/* plot.h */
int		plot_screen(t_info *info);

/* minimap.h */
void	plot_minimap(t_info *info);

/* pixel_put.c */
void	my_pixel_put(t_img *img, int x, int y, unsigned int color);

#endif
