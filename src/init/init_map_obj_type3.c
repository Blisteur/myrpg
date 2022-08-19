/*
** EPITECH PROJECT, 2021
** init_map_obj_type
** File description:
** file 3
*/

#include "rpg.h"

void init_mob_stats(object_t *p, int *array)
{
    p->stats->def = 0;
    p->stats->cur_hp = array[0];
    p->stats->max_hp = array[0];
    p->stats->extra_hp = 0;
    p->stats->speed = (float) array[1];
    p->stats->range = 0;
    p->stats->atk = (float) array[2];
    p->stats->atk_spd = 0;
    p->stats->grace = 0;
    p->stats->exp = 0;
    p->stats->max_exp = 0;
}

void init_gaper_obj(object_t *p, sfVector2f pos)
{
    int array[3] = {5, 1, 1};

    p->id = OBJ_MOB1;
    p->obj = create_elem("src/files/game/mobs.png", pos
    , rect(0, 0, 28, 38), 3);
    p->hit_box = (sfFloatRect) {pos.x, pos.y, 84, 114};
    p->stats = malloc(sizeof(stats_t));
    init_mob_stats(p, array);

}

void init_spider_obj(object_t *p, sfVector2f pos)
{
    int array[3] = {5, 1, 1};

    p->id = OBJ_MOB2;
    p->obj = create_elem("src/files/game/mobs.png", pos
    , rect(0, 152, 28, 38), 3);
    p->hit_box = (sfFloatRect) {pos.x, pos.y + 35, 84, 40};
    p->stats = malloc(sizeof(stats_t));
    init_mob_stats(p, array);
}

void init_fly_obj(object_t *p, sfVector2f pos)
{
    int array[3] = {2, 1, 1};

    p->id = OBJ_MOB3;
    p->obj = create_elem("src/files/game/mobs.png", pos
    , rect(0, 190, 28, 38), 3);
    p->hit_box = (sfFloatRect) {pos.x, pos.y + 65, 84, 35};
    p->stats = malloc(sizeof(stats_t));
    init_mob_stats(p, array);
}

void init_zelda_obj(object_t *p, sfVector2f pos)
{
    int array[3] = {5, 1, 1};

    p->id = OBJ_MOB4;
    p->obj = create_elem("src/files/game/mobs.png", pos
    , rect(0, 0, 28, 38), 5);
    p->hit_box = (sfFloatRect) {pos.x, pos.y, 84, 114};
    p->stats = malloc(sizeof(stats_t));
    init_mob_stats(p, array);
}