/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 00:05:35 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/10 01:01:27 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLOT_H
# define PLOT_H

# include	"../mlx-linux/mlx.h"
# include	"structure.h"
# include	"raycasting.h"

void	my_pixel_put(t_info *info, int x, int y, unsigned int color);
void	plot_screen(t_info *info);

#endif
