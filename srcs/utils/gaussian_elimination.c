/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gaussian_elimination.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 10:39:20 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/16 18:35:18 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<utils.h>

static void	set_line(double *matrix, size_t line, size_t target)
{
	size_t	l;

	l = target + 1;
	while (l < line)
	{
		matrix[target * line + l] /= matrix[target * line + target];
		l++;
	}
	matrix[target * line + target] = 1;
}

static void	reflect_line(double *matrix, size_t line, size_t row, size_t target)
{
	size_t	r;
	size_t	l;

	r = !target;
	while (r < row)
	{
		l = target + 1;
		while (l < line)
		{
			matrix[r * line + l] -= \
				matrix[target * line + l] * matrix[r * line + target];
			l++;
		}
		matrix[r * line + target] = 0;
		r++;
		if (r == target)
			r++;
	}
}

int	gaussian_elimination(double *matrix, size_t line, size_t row)
{
	size_t	r;

	r = 0;
	while (r < row)
	{
		set_line(matrix, line, r);
		reflect_line(matrix, line, row, r);
		r++;
	}
	return (0);
}
