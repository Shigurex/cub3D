/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gaussian_elimination.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 10:39:20 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/14 10:42:38 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<utils.h>

static void	set_line(double *matrix, size_t line, size_t target)
{
	size_t	l;

	l = target + 1;
	while (l < line)
	{
/* test */if(matrix[target * line + target] == 0.0){E exit(1);}
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
			matrix[r * line + l] -= matrix[target * line + l] * matrix[r * line + target];
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



//#include <stdlib.h>
//void print_matrix(double *matrix, size_t line, size_t row)
//{
//    for (size_t r = 0; r < row; r++)
//    {
//        for (size_t l = 0; l < line; l++)
//        {
//            printf("%lf,\t", matrix[r * line + l]);
//        }
//        printf("\n");
//    }
//}
//
//int main(int argc, char *argv[])
//{
//    if (argc < 2) {E return(1);}
//    double matrix[argc - 1];
//    for (size_t i = 0; i < argc - 1; i++)
//        matrix[i] = atof(argv[i + 1]);
//    size_t line = 1;
//    for (; line * (line - 1) < argc - 1; line++);
//    if (line * (line - 1) != argc - 1) {E return(1);}
//    size_t row = (argc - 1) / line;
//T print_matrix(matrix, line, row);
//Tn(line)
//Tn(row) STOP
//    Tn(Gaussian_elimination(matrix, line, row))  print_matrix(matrix, line, row);
//    return(0);
//
//}
