/*
** EPITECH PROJECT, 2021
** get obj
** File description:
** file 1
*/

#include "rpg.h"

int player_spe_obj(struct_t *store, game_room_t *tmp_ptr, object_t *tmp2_ptr)
{
    if (tmp2_ptr->id == OBJ_KEY) {
        remove_spe_obj(tmp2_ptr, tmp_ptr);
        store->game->player->key += 1;
        update_txt_inv(store->game->player->key,
        store->game->game_text->text[1]);
        audio_run_sound(store, SOUND_SELECT);
        return (0);
    }
    if (tmp2_ptr->id == OBJ_BOMB) {
        remove_spe_obj(tmp2_ptr, tmp_ptr);
        store->game->player->bomb += 1;
        update_txt_inv(store->game->player->bomb,
        store->game->game_text->text[0]);
        audio_run_sound(store, SOUND_SELECT);
        return (0);
    }
    return (1);
}

int player_get_coin(struct_t *store, game_room_t *tmp_ptr, object_t *tmp2_ptr)
{
    if (tmp2_ptr->id == OBJ_COIN) {
        remove_spe_obj(tmp2_ptr, tmp_ptr);
        store->game->player->money += 1;
        update_txt_inv(store->game->player->money,
        store->game->game_text->text[2]);
        audio_run_sound(store, SOUND_SELECT);
        return (0);
    }
    return (1);
}

int player_get_obj(struct_t *store, game_room_t *tmp_ptr, object_t *tmp2_ptr)
{
    if (tmp2_ptr->id == OBJ_MOB1 || tmp2_ptr->id == OBJ_MOB2
    || tmp2_ptr->id == OBJ_MOB3 || tmp2_ptr->id == OBJ_MOB4)
        return (0);
    if (tmp2_ptr->id == OBJ_PNJ && store->game->dialogue->lock == 0) {
        set_pnj_txt(store, tmp2_ptr, tmp_ptr);
    }
    if (player_get_coin(store, tmp_ptr, tmp2_ptr) == 0)
        return (0);
    if (player_spe_obj(store, tmp_ptr, tmp2_ptr) == 0)
        return (0);
    if (tmp2_ptr->id == OBJ_SPIKE) {
        damage_player(store, store->game->player, 2);
        return (0);
    }
    if (tmp2_ptr->id == OBJ_FIRE)
        damage_player(store, store->game->player, 1);
    return (1);
}