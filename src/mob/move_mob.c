/*
** EPITECH PROJECT, 2021
** move mob
** File description:
** move_mob
*/

#include "rpg.h"

void reset_hitbox(object_t *mob)
{
    if (mob->id == OBJ_MOB1)
        mob->hit_box = (sfFloatRect) {mob->obj->pos.x,
        mob->obj->pos.y, 84, 114};
    if (mob->id == OBJ_MOB2) {
        mob->hit_box = (sfFloatRect) {mob->obj->pos.x,
        mob->obj->pos.y + 35, 84, 40};
    }
    if (mob->id == OBJ_MOB3) {
        mob->hit_box = (sfFloatRect) {mob->obj->pos.x,
        mob->obj->pos.y + 45, 84, 35};
    }
}

void mob_set_pos(object_t *mob, float posx, float posy)
{
    mob->obj->pos.x += posx;
    mob->obj->pos.y += posy;
    sfSprite_setPosition(mob->obj->spr, mob->obj->pos);
    mob->hit_box.top = mob->obj->pos.y;
    mob->hit_box.left = mob->obj->pos.x;
    reset_hitbox(mob);
}

void mob_move_one(struct_t *store, object_t *mob, float posx, float posy)
{
    sfFloatRect tmpx = {0, 0, mob->hit_box.width, mob->hit_box.height};
    sfFloatRect tmpy = {0, 0, mob->hit_box.width, mob->hit_box.height};

    tmpx.left = mob->obj->pos.x + posx;
    tmpx.top = mob->obj->pos.y;
    tmpy.left = mob->obj->pos.x;
    tmpy.top = mob->obj->pos.y + posy;
    if (mob_hitbox(store, tmpx, mob) != 0)
        posx = 0;
    if (mob_hitbox(store, tmpy, mob) != 0)
        posy = 0;
    mob_set_pos(mob, posx, posy);
}

void mob_move_all(struct_t *store, object_t *mob)
{
    sfVector2f p_pos = {(store->game->player->pos.x),
    (store->game->player->pos.y)};
    float posx = 0.0;
    float posy = 0.0;

    if (store->game->map->changing_room != 0)
        return;
    if (p_pos.x - mob->obj->pos.x > 35)
        posx += get_distance(store, mob->stats->speed);
    else if (p_pos.x - mob->obj->pos.x < -35)
        posx -= (get_distance(store, mob->stats->speed));
    if (p_pos.y - mob->obj->pos.y > 35)
        posy += get_distance(store, mob->stats->speed);
    else if (p_pos.y - mob->obj->pos.y < -35)
        posy -= (get_distance(store, mob->stats->speed));
    mob_move_one(store, mob, posx, posy);
}