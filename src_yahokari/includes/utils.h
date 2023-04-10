/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 01:01:01 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/09 19:20:15 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include	<stdlib.h>
# include	<stdio.h>
# include	<math.h>
# include	"../libft/libft.h"
# include	"define.h"

/* exit_error.c */
void			exit_with_message(char *message);

/* safe_free.c */
void			safe_free_char_pointer(char **str);
void			safe_free_char_double_pointer(char ***str);

/* count.c */
size_t			count_split_size(char **str);

/* list.c */
void			insert_list(t_circ_list **list, char *str);
void			clear_list(t_circ_list **list);
void			print_list(t_circ_list *list);

/* rgb_to_color.c */
unsigned int	rgb_to_color(int red, int green, int blue);

/* angle.c */
double			convert_degree_within_two_pie(double degree);
double			degree_to_radian(double degree);

/* pos.c */
t_pos			assign_pos(double x, double y);
double			calculate_distance(t_pos pos1, t_pos pos2);

/* get_sign.c */
int				get_sign(double value);

#endif