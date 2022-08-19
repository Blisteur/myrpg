/*
** EPITECH PROJECT, 2021
** anim_obj
** File description:
** anim_obj
*/

#include "rpg.h"

static void anim_obj_loop(game_room_t *tmp, object_t *tmp2)
{
    for (int subnb = 0; subnb < tmp->nb_object; subnb += 1) {
        if (tmp2->id == OBJ_FIRE) {
            tmp2->obj->rect.left += 28;
            if (tmp2->obj->rect.left >= 224)
                tmp2->obj->rect.left = 0;
            sfSprite_setTextureRect(tmp2->obj->spr, tmp2->obj->rect);
        } if (tmp2->id == OBJ_MOB1)
            anim_gaper(tmp2);
        if (tmp2->id == OBJ_MOB2)
            anim_spider(tmp2);
        if (tmp2->id == OBJ_MOB3)
            anim_fly(tmp2);
        if (tmp2->id == OBJ_MOB4)
            anim_zelda(tmp2);
        tmp2 = tmp2->next;
    }
}

void anim_obj(struct_t *store)
{
    game_room_t *tmp = store->game->map->first_room;
    object_t *tmp2 = store->game->map->first_room->first_object;

    for (int nb = 0; nb < store->game->map->nb_room; nb += 1) {
        anim_obj_loop(tmp, tmp2);
        tmp = tmp->next;
        if (nb < (store->game->map->nb_room - 1))
            tmp2 = tmp->first_object;
    }
}