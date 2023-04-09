#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include "hoge.h"

typedef enum{
    E,
    NE,
    N,
    NW,
    W,
    SW,
    S,
    SE,
}t_direction_8;

typedef struct enemy
{
    t_direction_8 direction;
    unsigned time;
}t_enemy;

#define ENEMY_FINND_TIME 0x400
#define ENEMY_FIRE_TIME 0x200

#define ENEMY_FINND_LEN 16

#define ENEMY_IMG_HIGHT 300

t_enemy *t_enemy_init(t_direction_8 dir)
{
    t_enemy *r;

    r = malloc(sizeof(t_enemy));
    if(r)
    {
        r->direction = dir;
        r->time = ENEMY_FINND_TIME;
    }
    return (r);
}

t_direction_8 enemy_direction(hoge_coordinate v);

int enemy_move(t_enemy *enemy, hoge_coordinate enemy_c, hoge_coordinate man_c, hoge_map_node **map)
{
    double len;
    hoge_coordinate v;

    v.x = enemy_c.x - man_c.x;
    v.y = enemy_c.y - man_c.y;
    len = (v.x * v.x) + (v.y * v.y);
    if (len < ENEMY_FINND_LEN * ENEMY_FINND_LEN && enemy_sight(map, enemy_c, man_c))
    {
        enemy->time--;
        if (enemy->time == 0)
            return (1);
        else if (enemy->time < ENEMY_FIRE_TIME)
            enemy->direction = enemy_direction(v);
    }
    else
        enemy->time = ENEMY_FINND_TIME;
    return (0);
}

t_direction_8 enemy_direction(hoge_coordinate v)
{
    double gradient;

    gradient = v.y / v.x;
    if (gradient >= tan(-0.125 * M_PI) && gradient <= tan(0.125 * M_PI) && v.x >= 0)
        return (E);
    if (gradient >= tan(-0.125 * M_PI) && gradient <= tan(0.125 * M_PI) && v.x < 0)
        return (W);
    if (gradient > tan(0.125 * M_PI) && gradient <= tan(0.375 * M_PI) && v.x >= 0)
        return (NE);
    if (gradient > tan(0.125 * M_PI) && gradient <= tan(0.375 * M_PI) && v.x < 0)
        return (SW);
    if (gradient < tan(-0.125 * M_PI) && gradient >= tan(-0.375 * M_PI) && v.x >= 0)
        return (SE);
    if (gradient < tan(-0.125 * M_PI) && gradient >= tan(-0.375 * M_PI) && v.x < 0)
        return (NW);
    if (v.y >= 0)
        return (N);
    if (v.y < 0)
        return (S);
}













