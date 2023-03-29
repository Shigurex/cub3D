/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:23:49 by yahokari          #+#    #+#             */
/*   Updated: 2023/03/28 16:40:19 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include	<math.h>
# include	<stdbool.h>
# include	<stdio.h>
# include	"structure.h"
# include	"global.h"

t_pos			find_block_pos(t_pos intersection, double angle, int direction);
int				check_block(t_pos intersection, double angle, int direction);
int				get_sign(double angle, int direction);
t_intersection	check_intersection(t_info *info, double angle);
double			convert_to_radian(double degree);
double			calculate_distance(t_info *info, t_pos wall);

#endif
