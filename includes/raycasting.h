/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:23:49 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/09 20:07:27 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include	<math.h>
# include	<stdbool.h>
# include	<stdio.h>
# include	"structure.h"
# include	"map.h"

t_intersection	check_intersection(t_info *info, double angle);
double			convert_to_radian(double degree);
double			calculate_distance(t_info *info, t_pos wall);

#endif
