/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:56:06 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/10 15:04:30 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include	<stdio.h>
# include	<stdlib.h>
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

#endif
