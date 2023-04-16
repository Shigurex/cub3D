/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:48:39 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/16 21:36:42 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include	<math.h>
# include	"define.h"
# include	"utils.h"

/* raycasting.c */
t_ray		check_intersection(t_info *info, double angle);

/* raycasting_utils.c */
t_axis		get_closer_axis(t_info *info, \
	t_pos horizontal_ray, t_pos vertical_ray);
t_block		get_bumped_block(t_info *info, \
	t_pos ray, double angle, t_axis axis);
t_img		get_wall_img(t_info *info, t_direction direction);
t_direction	get_wall_direction(double angle, t_axis axis);

/* door.c */
bool		is_door_hit(t_info *info, t_ray *ray, t_block block);

#endif
