/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flooring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:21:26 by yahokari          #+#    #+#             */
/*   Updated: 2023/03/28 16:23:57 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	flooring(unsigned int set)
{
	static unsigned int	color;

	if (set)
		color = set;
	return (color);
}
