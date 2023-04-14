/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:56:06 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/14 15:26:48 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
#include "debug.h"//------------------------test

# include	<stdio.h>
# include	<stdlib.h>
# include	<math.h>
# include	<stddef.h>
# include	"define.h"

/* exit.c */
void			exit_with_message(char *message);

/* free.c */
void			safe_free_char_pointer(char **str);
void			safe_free_char_double_pointer(char ***str);

/* list.c */
void			insert_list(t_circ_list **list, char *str);
void			clear_list(t_circ_list **list);
void			print_list(t_circ_list *list);

/* string.c */
bool			is_char_in_str(int c, char *str);

/* color.c */
unsigned int	trgb_to_color(int transparency, int red, int green, int blue);

/* pos.c */
t_pos			assign_pos(double x, double y);
double			calculate_distance(t_pos pos1, t_pos pos2);

/* count.c */
size_t			count_split_size(char **str);

/* sign.c */
int				get_sign(double value);

/* solve_vector.c */
t_pos			sva_p_tvb_e_vc(t_pos va, t_pos vb, t_pos vc);
t_pos			va_p_svb_e_tvc(t_pos va, t_pos vb, t_pos vc);

/* angle.c */
double			convert_degree_within_two_pie(double degree);
double			degree_to_radian(double degree);

/* sign.c */
int				get_sign(double value);

/* gaussian_elimination */
int				gaussian_elimination(double *matrix, size_t line, size_t row);

#endif
