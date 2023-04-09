/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:49:17 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/09 18:33:57 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include	<stdbool.h>
# include	"utils.h"
# include	"define.h"

/* raycasting_utils.c */
t_type			get_bumped_block(t_info *info, \
	t_pos ray, double angle, t_axis axis);
int				calculate_img_col(t_info *info, \
	t_direction direction, t_pos pos);
t_axis			get_closer_axis(t_info *info, \
	t_pos horizontal_ray, t_pos vertical_ray);

/* raycasting.c */
t_intersection	check_intersection(t_info *info, double angle);

#endif
