/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:56:36 by yahokari          #+#    #+#             */
/*   Updated: 2023/04/03 12:13:09 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"define.h"
#include	"parse.h"
#include	"setup.h"
#include	"utils.h"

int	main(int argc, char **argv)
{
	t_info	info;

	info.mlx = mlx_init();
	if (argc != 2)
		exit_with_message("invalid number of arguments");
	readfile(&info, argv[1]);
	init_setup(&info);
	mlx_loop(info.mlx);
	return (0);
}
