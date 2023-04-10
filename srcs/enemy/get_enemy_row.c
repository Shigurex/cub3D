#include "utils.h"
#include "define.h"
#include <math.h>

t_pos enemy_lay_info(t_character *a_enemy, t_ray *ray, t_info *i)
{
	t_pos	p_img_v;
	t_pos	img_row_v;
	t_pos	ray_v;

	ray_v.x = tan(ray->yaw / 180.0);
	ray_v.y = 1.0 / tan(ray->yaw / 180.0);
	p_img_v.x = a_enemy->pos.x - i->player.pos.x;
	p_img_v.y = a_enemy->pos.y - i->player.pos.y;
	img_row_v.x = tan(fmod(ray->yaw + 90, 360) / 180.0);
	img_row_v.y = 1.0 / tan(fmod(ray->yaw + 90, 360)/ 180.0);
	return (VA_p_sVB_e_tVC(p_img_v, img_row_v, ray_v));
}

