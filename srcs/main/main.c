/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 10:56:05 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/15 21:08:18 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"cub3D.h"

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 2)
		exit_with_message("invalid number of arguments");
	setup_info(&info, argv[1]);
	plot_screen(&info);
	mlx_loop(info.mlx);
	return (0);
}
