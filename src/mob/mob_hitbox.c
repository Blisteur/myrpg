/*
** EPITECH PROJECT, 2020
** B-MUL-200-NCY-2-1-myrpg-nathan.chiodin
** File description:
** mob_hitbox.c
*/

#include "rpg.h"

int mob_get_obj(object_t *tmp2_ptr)
{
    if (tmp2_ptr->id == OBJ_KEY || tmp2_ptr->id == OBJ_BOMB ||
    tmp2_ptr->id == OBJ_COIN)
        return (0);
    return (1);
}

int is_player(sfFloatRect tmp, struct_t *store, object_t *mob)
{
    if (sfFloatRect_intersects(&tmp, &store->game->player->hit_box,
    NULL) == sfTrue) {
        damage_player(store, store->game->player,
        mob->stats->atk);
        audio_run_sound(store, SOUND_ATTACK);
        return (1);
    }
    return (0);
}

int mob_hitbox(struct_t *store, sfFloatRect tmp, object_t *mob)
{
    game_room_t *tmp_ptr = store->game->map->first_room;
    object_t *tmp2_ptr = store->game->map->first_room->first_object;
    int cur = store->game->player->room_id;

    if (is_player(tmp, store, mob) == 1)
        return (1);
    for (int nb = 0; nb < store->game->map->nb_room; nb += 1) {
        for (int subnb = 0; tmp_ptr->id == cur
            && subnb < tmp_ptr->nb_object; subnb += 1) {
            if (sfFloatRect_intersects(&tmp, &tmp2_ptr->hit_box,
            NULL) == sfTrue && mob->id != tmp2_ptr->id)
                return (mob_get_obj(tmp2_ptr));
            tmp2_ptr = tmp2_ptr->next;
        }
        tmp_ptr = tmp_ptr->next;
        if (nb < (store->game->map->nb_room - 1))
            tmp2_ptr = tmp_ptr->first_object;
    }
    return (0);
}