/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:49:17 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/07 09:38:08 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include	<stdbool.h>
# include	"utils.h"
# include	"define.h"

/* raycasting.c */
t_intersection	check_intersection(t_info *info, double angle);

#endif
