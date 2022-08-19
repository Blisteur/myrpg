/*
** EPITECH PROJECT, 2021
** player hit
** File description:
** file 1
*/

#include "rpg.h"

void player_fire_up(struct_t *store, player_t *player)
{
    if (store->game->clock->master_time.microseconds
        - player->cooldown.microseconds <=
        (1000000 - (player->stats->atk_spd * 10000)))
        return;
    audio_run_sound(store, SOUND_ATTACK);
    player->player_atk_type = 1;
    if (store->game->player->bow == 0) {
        player->rec.top = 199;
        player->rec.left = 0;
        player->rec.height = 33;
        player->rec.width = 32;
        hit_with_sword(store, player);
    } else {
        player->rec.top = 301;
        player->rec.left = 0;
        player->rec.height = 23;
        player->rec.width = 21;
        player->player_arrows = add_arrows(store, player->player_arrows
                    , (sfVector2f) {player->pos.x + 32, player->pos.y + 70});
    }
}

void player_fire_down(struct_t *store, player_t *player)
{
    if (store->game->clock->master_time.microseconds
        - player->cooldown.microseconds <=
        (1000000 - (player->stats->atk_spd * 10000)))
        return;
    audio_run_sound(store, SOUND_ATTACK);
    player->player_atk_type = 2;
    if (store->game->player->bow == 0) {
        player->rec.top = 100;
        player->rec.left = 0;
        player->rec.height = 33;
        player->rec.width = 32;
        hit_with_sword(store, player);
    } else {
        player->rec.top = 232;
        player->rec.left = 0;
        player->rec.height = 23;
        player->rec.width = 21;
        player->player_arrows = add_arrows(store, player->player_arrows
                    , (sfVector2f) {player->pos.x + 60, player->pos.y + 10});
    }
}

void player_fire_left(struct_t *store, player_t *player)
{
    if (store->game->clock->master_time.microseconds
        - player->cooldown.microseconds <=
        (1000000 - (player->stats->atk_spd * 10000)))
        return;
    audio_run_sound(store, SOUND_ATTACK);
    player->player_atk_type = 3;
    if (store->game->player->bow == 0) {
        player->rec.top = 133;
        player->rec.left = 0;
        player->rec.height = 33;
        player->rec.width = 32;
        hit_with_sword(store, player);
    } else {
        player->rec.top = 255;
        player->rec.left = 0;
        player->rec.height = 23;
        player->rec.width = 21;
        player->player_arrows = add_arrows(store, player->player_arrows
                    , (sfVector2f) {player->pos.x + 60, player->pos.y + 60});
    }
}

void player_fire_right(struct_t *store, player_t *player)
{
    if (store->game->clock->master_time.microseconds
        - player->cooldown.microseconds <=
        (1000000 - (player->stats->atk_spd * 10000)))
        return;
    audio_run_sound(store, SOUND_ATTACK);
    player->player_atk_type = 4;
    if (store->game->player->bow == 0) {
        player->rec.top = 166;
        player->rec.left = 0;
        player->rec.height = 33;
        player->rec.width = 32;
        hit_with_sword(store, player);
    } else {
        player->rec.top = 278;
        player->rec.left = 0;
        player->rec.height = 23;
        player->rec.width = 21;
        player->player_arrows = add_arrows(store, player->player_arrows
                    , (sfVector2f) {player->pos.x, player->pos.y + 32});
    }
}