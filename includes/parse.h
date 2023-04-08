/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:37:11 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/05 00:54:01 by yahokari         ###   ########.fr       */
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
void	input_texture(t_info *info, char *line);

/* map.c */
void	input_map(t_info *info, char *line);

/* convert.c */
void	make_map_from_list(t_info *info);
void	clear_map(t_info *info);

#endif
