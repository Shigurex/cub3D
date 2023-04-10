/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:17:30 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/10 15:11:08 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP_H
# define SETUP_H

# include	<fcntl.h>
# include	"define.h"
# include	"utils.h"
# include	"plot.h"

/* setup.c */
void	setup_info(t_info *info, char *file_name);
int		close_window(t_info *info);

/* init.c */
void	init_basic_info(t_info *info);
void	init_img(t_info *info, t_img *img, int width, int height);

/* read.c */
void	read_map_file(t_info *info, char *file_name);

/* key.c */
int		handle_key_press_action(int keycode, t_info *info);
int		handle_key_release_action(int keycode, t_info *info);

/* textures.c */
void	input_texture(t_info *info, char *line);

/* map.c */
void	input_map(t_info *info, t_circ_list **map_list, char *line);

/* convert.c */
void	make_map_from_list(t_info *info, t_circ_list *map_list);
void	clear_map(t_info *info);

#endif
