/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 03:40:54 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/10 03:41:18 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../../includes/setting.h"
#include "debug.h"

int setting(char *filename, t_info *i)
{
	char	*file;

	file = read_file(filename);
	if (!file || map(0, 0, file) == MAP_ERROR)
		return (1);
	set_human(i, skip_map(file));
	return (0);
}

char	*read_file(char *filename)
{
	int		fd;
	char	*r;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	r = reading_file(fd, 0);
	close(fd);
	return (r);
}

char *reading_file(int fd, size_t B)
{
	char	buf[BUFFERSIZE];
	ssize_t	i;
	char	*r;

	i = read(fd, buf, BUFFERSIZE);
	if (i < 0)
		return (NULL);
	else if (i == 0)
	{
		r = malloc(B + 1);
		r[B] = '\0';
	}
	else
		r = reading_file(fd, B + i);
	if (r)
		ft_memcpy(r + B, buf, i);
	return (r);
}
