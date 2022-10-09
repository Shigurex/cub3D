/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 03:37:57 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/10 03:40:19 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTING_H
# define SETTING_H

# define BUFFERSIZE 1024

# include	"../libft/libft.h"
# include	"cub3D.h"

int				setting(char *filename, t_info *i);
char			*skip_map(char *file);
int				check_map_char(char *file);
int				set_map_size(char *file, size_t *x, size_t *y);
int				set_map_size(char *file, size_t *x, size_t *y);
void			set_map(unsigned char	*map, char *file, size_t x);
int				check_map_shape(unsigned char	*map, size_t x, size_t y);
void			set_human(t_info *i, char *mapf);
char			*read_file(char *filename);
char			*reading_file(int fd, size_t B);
unsigned char	*mk_map(char *file, size_t *x, size_t *y);

#endif
