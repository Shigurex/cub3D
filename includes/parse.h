/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:37:11 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/03 10:52:37 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# define OPEN_ERROR -1

# define EMPTY_STRING ""

# include	<fcntl.h>
# include	<unistd.h>
# include	<stdbool.h>
# include	"../libft/libft.h"
# include	"define.h"
# include	"utils.h"

/* readfile.c */
void	readfile(t_info *info, char *file_name);

/* texture.c */
void	input_texture(t_info *info, char **split_line);

/* color.c */
void	input_color(t_info *info, char **split_line);

/* map.c */
void	input_map(t_info *info, char *line);

#endif
