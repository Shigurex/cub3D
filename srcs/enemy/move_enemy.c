#include <math.h>
#include "define.h"
#include "utils.h"

int	enemy_move(t_info *i)
{
	size_t  l;
	size_t	r;

	l = 0;
	r = i->enermy_num;
	while (l < i->enermy_num)
	{
		if (i->enermy[l].is_alive)
		{
			a_enemy_move(i, i->enermy + l);
		}
		else
			r--;
		l++;
	}
	return (!r);
}

int a_enemy_move(t_info *i, t_character *enemy)
{
	double len;
	t_pos v;

	v.x = i->player.pos.x - enemy->pos.x;
	v.y = i->player.pos.y - enemy->pos.y;
	len = (v.x * v.x) + (v.y * v.y);
	if (len < ENEMY_FINND_LEN * ENEMY_FINND_LEN && enemy_sight(i))
	{
		enemy->time--;
		if (enemy->time == 0)
			return (1);
		else if (enemy->time < ENEMY_FIRE_TIME)
			enemy->yaw = vector_to_8direction(v);
	}
	else
		enemy->time = ENEMY_FINND_TIME;
	return (0);
}














