/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:25:48 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/10 03:42:37 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

# include	<stdlib.h>
# include	<stdio.h>
# include	<fcntl.h>
# include	"../libft/libft.h"
# include	"structure.h"
# include	"structure.h"
# include	"cub3D.h"

# define BITS_PER_PIXEL 0
# define SIZE_LINE 1
# define ENDIAN 2

int	map(size_t, size_t, char *);

#endif
