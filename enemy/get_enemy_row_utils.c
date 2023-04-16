#include "utils.h"
#include "define.h"
#include <math.h>


typedef struct s_enemy_ray
{
	t_pos	see_v;
	double	len;
	double	img_line;
	t_img	img;
}t_enemy_ray;


void swap_t_enemy_ray(t_enemy_ray *a, t_enemy_ray *b)
{
	t_enemy_ray buff;

	buff = *a;
	*a = *b;
	*b = buff;
}


void insert_enemy_ray(t_enemy_ray *arr, size_t size)
{
	while (size)
	{
		if (arr[size].len < arr[size - 1].len)
			swap_t_enemy_ray(arr + size, arr + (size - 1));
		else
			break;
		size--;
	}
}
