/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:22:06 by yahokari          #+#    #+#             */
/*   Updated: 2023/03/28 16:23:53 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ceiling(unsigned int set)
{
	static unsigned int	color;

	if (set)
		color = set;
	return (color);
}
