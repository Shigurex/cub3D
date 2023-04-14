/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 10:56:05 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/14 10:56:27 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"cub3D.h"

// __attribute__((destructor))
// static void	end()
// {
// 	system("leaks -q cub3D");
// }

int	main(int argc, char **argv)
{
	t_info	info;

	(void)argv;
	if (argc != 2)
		exit_with_message("invalid number of arguments");
	setup_info(&info, argv[1]);
	plot_screen(&info);
	mlx_loop(info.mlx);
	return (0);
}
