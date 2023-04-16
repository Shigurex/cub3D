#include "utils.h"
#include "define.h"
#include "plot.h"
#include <math.h>


typedef struct s_enemy_ray
{
	t_pos	see_v;
	double	len;
	double	img_line;
	t_img	img;
}t_enemy_ray;

void enemy_cast(t_ray *ray, t_info *i)
{
	t_enemy_ray *arr;
	size_t l;

	arr = malloc(i->enemy_num * sizeof(t_enemy_ray));
	if (!arr)
		exit_with_message("malloc error\n");
	l = 0;
	while (l < i->enemy_num)
	{
		arr[l] = enemy_lay_info(i->enemy + l, ray, i);
		l++;
	}
	enemy_set_pic(arr, sort_enemy_ray(arr, i->enemy_num, ray->distance), i, ray);
	free(arr);
}

size_t sort_enemy_ray(t_enemy_ray *arr, size_t size, double len)
{
	ssize_t		b;
	ssize_t		f;
	t_enemy_ray	buff;

	b = size - 1;
	f = 0;
	while (f <= b)
	{
		if (arr[f].len > len || arr[f].img_line > 1.0)
		{
			swap_t_enemy_ray(arr + f, arr + b);
			b--;
		}
		else
		{
			insert_enemy_ray(arr, f);
			f++;
		}
	}
	return (b + 1);
}

t_enemy_ray enemy_lay_info(t_character *a_enemy, t_ray *ray, t_info *i)
{
	t_pos		p_img_v;
	t_pos		img_row_v;
	t_pos		ray_v;
	t_enemy_ray	r;

	ray_v.x = tan(ray->yaw / 180.0);
	ray_v.y = 1.0 / tan(ray->yaw / 180.0);
	p_img_v.x = a_enemy->pos.x - i->player.pos.x;
	p_img_v.y = a_enemy->pos.y - i->player.pos.y;
	img_row_v.x = tan(fmod(ray->yaw + 90, 360) / 180.0);
	img_row_v.y = 1.0 / tan(fmod(ray->yaw + 90, 360)/ 180.0);
	ray_v = VA_p_sVB_e_tVC(p_img_v, img_row_v, ray_v);
	r.img_line = ray_v.x + 0.5;
	r.len = ray_v.y;
	r.img = i->textures.enermy[ \
	((vector_to_8direction(p_img_v) + 180) / 45) % ENERMY_IMGS];
	return (r);
}

void	enemy_set_pic(t_enemy_ray *arr, size_t l, t_info *i, t_ray *ray)
{
	size_t a;
	size_t y;
	double	pitch;
	double	height;

	a = 0;
	while (a < l)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			pitch = i->player.pitch + \
				((double)y - WIN_HEIGHT / 2) / WIN_HEIGHT * SIGHT_PITCH;
			height = 0.5 + arr[a].len * cos(degree_to_radian(ray->yaw - i->player.yaw)) * tan(degree_to_radian(pitch));
			if (height < 0 || 1 < height)
				my_pixel_put(&i->screens.enermy, ray->row_win, y, TRANSPARENT);
			else
				my_pixel_put(&i->screens.enermy, ray->row_win, y, my_pixel_get(arr[a].img, \
				(int)round(arr[a].img_line * arr[a].img.width), height * (arr[a].img.height - 1)));
			y++;
		}
		a++;
	}
	
}
