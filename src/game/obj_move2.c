/*
** EPITECH PROJECT, 2021
** obj_move
** File description:
** file 2
*/

#include "rpg.h"

void hurt_mob(struct_t *store, game_room_t *room, object_t *mob)
{
    float dmg = store->game->player->stats->atk - mob->stats->def;

    if (dmg < 1)
        dmg = 1;
    mob->stats->cur_hp -= dmg;
    if (mob != NULL && mob->stats->cur_hp <= 0) {
        store->game->player->stats->exp += 1;
        if (store->game->player->stats->exp >=
        store->game->player->stats->max_exp)
            level_up(store);
        remove_spe_obj(mob, room);
    }
}

int arrow_get_obj(struct_t *store, game_room_t *tmp_ptr, object_t *tmp2_ptr)
{
    if (tmp2_ptr->id == OBJ_KEY || tmp2_ptr->id == OBJ_BOMB ||
    tmp2_ptr->id == OBJ_COIN || tmp2_ptr->id == OBJ_SPIKE)
        return (0);
    if (tmp2_ptr->id == OBJ_MOB1 || tmp2_ptr->id == OBJ_MOB2 ||
    tmp2_ptr->id == OBJ_MOB3) {
        hurt_mob(store, tmp_ptr, tmp2_ptr);
        return (0);
    }
    if (tmp2_ptr->id == OBJ_FIRE)
        change_obj_fire(tmp2_ptr);
    return (1);
}