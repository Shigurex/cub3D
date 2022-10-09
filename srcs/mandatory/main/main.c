/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:49:54 by yahokari          #+#    #+#             */
/*   Updated: 2022/10/09 17:34:41 by yahokari         ###   ########.fr       */
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
	t_pos pos = check_intersection(&info, convert_to_radian(info.direction));
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
			else if (x == (size_t)(pos.x) && y == (size_t)(pos.y))
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
	printf("(%f, %f) -> (%ld, %ld)\n", pos.x, pos.y, (size_t)pos.x, (size_t)pos.y);
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
	init_setup(&info);
	mlx_loop(info.mlx);
	return (0);
}
