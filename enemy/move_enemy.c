#include <math.h>
#include "define.h"
#include "utils.h"

static int a_enemy_move(t_info *i, t_character *enemy);

int	enemy_move(t_info *i)
{
	size_t  l;
	size_t	r;

	l = 0;
	r = i->enemy_num;
	while (l < i->enemy_num)
	{
		if (i->enemy[l].is_alive)
		{
			if (a_enemy_move(i, i->enemy + l))
				i->player.is_alive = false;
		}
		else
			r--;
		l++;
	}
	return (!r);
}

static int a_enemy_move(t_info *i, t_character *enemy)
{
	double len;
	t_pos v;

	v.x = i->player.pos.x - enemy->pos.x;
	v.y = i->player.pos.y - enemy->pos.y;
	len = (v.x * v.x) + (v.y * v.y);
	if (len < ENEMY_FIND_LEN * ENEMY_FIND_LEN && enemy_sight(i, enemy))
	{
		if (enemy->time >= ENEMY_FIND_TIME)
			return (1);
		else if (enemy->time >= ENEMY_FIRE_TIME)
			enemy->yaw = vector_to_8direction(v);
		enemy->time++;
	}
	else
		enemy->time = 0;
	return (0);
}
