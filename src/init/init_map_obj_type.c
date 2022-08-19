/*
** EPITECH PROJECT, 2021
** init_map_type
** File description:
** file 1
*/

#include "rpg.h"

void init_void_obj(object_t *p, sfVector2f pos)
{
    p->id = OBJ_VOID;
    p->obj = create_elem("src/files/game/obstacles.png", pos
    , rect(0, 31, 27, 31), 4);
    p->hit_box = (sfFloatRect) {pos.x + 4, pos.y + 16, 108 - 8, 124 - 32};
    p->stats = NULL;
}

void init_spike_obj(object_t *p, sfVector2f pos)
{
    p->id = OBJ_SPIKE;
    p->obj = create_elem("src/files/game/obstacles.png", pos
    , rect(0, 93, 27, 31), 4);
    p->hit_box = (sfFloatRect) {pos.x + 4, pos.y + 4, 108 - 8, 124 - 8};
    p->stats = NULL;
}

void init_rock_obj(object_t *p, sfVector2f pos)
{
    int tmp = (rand() % 3) + 1;

    if (tmp == 1)
        p->obj = create_elem("src/files/game/obstacles.png", pos
        , rect(0, 0, 27, 31), 4);
    if (tmp == 2)
        p->obj = create_elem("src/files/game/obstacles.png", pos
        , rect(27, 0, 27, 31), 4);
    if (tmp == 3)
        p->obj = create_elem("src/files/game/obstacles.png", pos
        , rect(54, 0, 27, 31), 4);
    p->id = OBJ_ROCK;
    p->hit_box = (sfFloatRect) {pos.x + 4, pos.y + 4, 108 - 8, 124 - 8};
    p->stats = NULL;
}

void init_fire_obj(object_t *p, sfVector2f pos)
{
    p->id = OBJ_FIRE;
    p->obj = create_elem("src/files/game/fire.png", pos
    , rect(0, 0, 28, 30), 4);
    p->hit_box = (sfFloatRect) {pos.x + 4, pos.y + 4, 112 - 8, 120 - 8};
    p->stats = NULL;
}

void init_poop_obj(object_t *p, sfVector2f pos)
{
    p->id = OBJ_POOP;
    p->obj = create_elem("src/files/game/obstacles.png", pos
    , rect(0, 62, 27, 31), 4);
    p->hit_box = (sfFloatRect) {pos.x + 4, pos.y + 4, 108 - 8, 124 - 8};
    p->stats = NULL;
}