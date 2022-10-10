/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 00:05:35 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/10 11:30:57 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLOT_H
# define PLOT_H

# include	"../mlx-linux/mlx.h"
# include	"structure.h"
# include	"raycasting.h"
# include   "global.h"

void	my_pixel_put(t_info *info, int x, int y, unsigned int color);
void	plot_screen(t_info *info);

#endif
