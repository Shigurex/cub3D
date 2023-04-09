/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:28:23 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/09 21:06:30 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"utils.h"

unsigned int	rgb_to_color(int red, int green, int blue)
{
	unsigned int	color;

	color = 0;
	color |= (unsigned int)red << 16;
	color |= (unsigned int)green << 8;
	color |= (unsigned int)blue;
	return (color);
}
