/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:13:50 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/16 21:43:47 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"raycasting.h"

bool	is_door_hit(t_info *info, t_ray *ray, t_block block)
{
	t_pos	va;
	t_pos	vb;
	t_pos	vc;
	t_pos	r;

	va = va_m_vb(block.door_begin, info->player.pos);
	vb = va_m_vb(block.door_end, block.door_begin);
	vb.x += 0.000001;
	vc = va_m_vb(ray->pos, info->player.pos);
	r = va_p_svb_e_tvc(va, vb, vc);
	if (r.x < 0 || 1 < r.x || r.y < 0)
		return (false);
	ray->pos = assign_pos(info->player.pos.x + r.y * vc.x, \
		info->player.pos.y + r.y * vc.y);
	return (true);
}
