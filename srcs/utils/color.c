/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:37:35 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/10 14:39:46 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	trgb_to_color(int transparency, int red, int green, int blue)
{
	unsigned int	color;

	color = 0;
	color |= (unsigned int)transparency << 24;
	color |= (unsigned int)red << 16;
	color |= (unsigned int)green << 8;
	color |= (unsigned int)blue;
	return (color);
}
