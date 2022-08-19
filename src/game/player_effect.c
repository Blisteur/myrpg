/*
** EPITECH PROJECT, 2021
** player_effect
** File description:
** file 1
*/

#include "rpg.h"

void player_bow(struct_t *store, player_t *player)
{
    if (player->bow == 0)
        player->bow = 1;
    else
        store->game->player->bow = 0;
}

void create_bomb(struct_t *store, player_t *player)
{
    player->player_bomb = malloc(sizeof(player_bomb_t));
    player->player_bomb->pos.x = player->pos.x;
    player->player_bomb->pos.y = player->pos.y;
    player->player_bomb->bomb = create_elem("src/files/game/items.png"
    , player->player_bomb->pos, rect(0, 0, 20, 20), 4);
    player->player_bomb->countdown.microseconds
    = (store->game->clock->master_time.microseconds + 3000000);
}

void player_bomb(struct_t *store, player_t *player)
{
    if (player->bomb <= 0 || player->player_bomb != NULL)
        return;
    player->bomb -= 1;
    update_txt_inv(store->game->player->bomb, store->game->game_text->text[0]);
    create_bomb(store, player);
    audio_run_sound(store, SOUND_ATTACK);
}