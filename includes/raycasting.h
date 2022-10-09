/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:23:49 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/09 20:50:39 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include	<math.h>
# include	<stdbool.h>
# include	<stdio.h>
# include	"structure.h"
# include	"global.h"

t_intersection	check_intersection(t_info *info, double angle);
double			convert_to_radian(double degree);
double			calculate_distance(t_info *info, t_pos wall);

#endif
