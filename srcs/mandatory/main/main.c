/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:49:54 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/09 20:08:39 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../../includes/cub3D.h"

void	init_setup(t_info *info)
{
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, DIS_X, DIS_Y, "cub3D");
	mlx_hook(info->win, ON_DESTROY, 1L << 0, close_window, info);
	mlx_hook(info->win, ON_KEYDOWN, 1L << 0, handle_key_input, info);
	info->img.address = mlx_new_image(info->mlx, DIS_X, DIS_Y);
}

void	display(t_info info)
{
	size_t x = 0;
	size_t y = 0;
	t_intersection intersec = check_intersection(&info, convert_to_radian(info.direction));
	y = 0;
	while (1)
	{
		x = 0;
		if (map(x, y, NULL) == MAP_ERROR)
			break;
		while (1)
		{
			int i;
			i = map(x, y, NULL);
			if (x == (size_t)(info.player.x) && y == (size_t)(info.player.y))
				printf("x");
			else if (x == (size_t)(intersec.wall.x) && y == (size_t)(intersec.wall.y))
				printf("o");
			else if (i == BLOCK)
				printf("#");
			else if (i == SPACE)
				printf(" ");
			else if (i == NONE)
				printf("+");
			else 
				break;
			x++;
		}
		printf("\n");
		y++;
	}
	//printf("intersec: (%f, %f), distance: %f, direction: %d, img_col: %ld\n", intersec.wall.x, intersec.wall.y, intersec.distance, intersec.wall_direction, intersec.img_col);
}

int	main(int argc, char *argv[])
{
	t_info	info;

	if (argc < 2)
	{
		printf("set arg!\n");
		return (0);
	}
	if (setting(argv[1], &info))
	{
		printf("can't set!\n");
		return (0);
	}
	display(info);
	//init_setup(&info);
	//mlx_loop(info.mlx);
	return (0);
}
