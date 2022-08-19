/*
** EPITECH PROJECT, 2021
** init_map_obj_type
** File description:
** file 2
*/

#include "rpg.h"

void init_metal_obj(object_t *p, sfVector2f pos)
{
    p->id = OBJ_METAL;
    p->obj = create_elem("src/files/game/obstacles.png", pos
    , rect(0, 31, 27, 31), 4);
    p->hit_box = (sfFloatRect) {pos.x + 4, pos.y + 32, 108 - 8, 124 - 64};
    p->stats = NULL;
}

void init_key_obj(object_t *p, sfVector2f pos)
{
    p->id = OBJ_KEY;
    p->obj = create_elem("src/files/game/items.png", pos
    , rect(20, 0, 20, 20), 4);
    p->hit_box = (sfFloatRect) {pos.x + 4, pos.y + 4, 80 - 8, 80 - 8};
    p->stats = NULL;
}

void init_bomb_obj(object_t *p, sfVector2f pos)
{
    p->id = OBJ_BOMB;
    p->obj = create_elem("src/files/game/items.png"
    , pos, rect(0, 0, 20, 20), 4);
    p->hit_box = (sfFloatRect) {pos.x + 4, pos.y + 4, 80 - 8, 80 - 8};
    p->stats = NULL;
}

void init_coin_obj(object_t *p, sfVector2f pos)
{
    p->id = OBJ_COIN;
    p->obj = create_elem("src/files/game/items.png", pos
    , rect(40, 0, 20, 20), 4);
    p->hit_box = (sfFloatRect) {pos.x + 4, pos.y + 4, 80 - 8, 80 - 8};
    p->stats = NULL;
}

void init_pnj_obj(object_t *p, sfVector2f pos)
{
    p->id = OBJ_PNJ;
    p->obj = create_elem("src/files/game/pnj.png", pos
    , rect(0, 0, 25, 38), 4);
    p->hit_box = (sfFloatRect) {pos.x, pos.y, 108, 124};
    p->stats = NULL;
}