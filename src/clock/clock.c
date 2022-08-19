/*
** EPITECH PROJECT, 2021
** clock
** File description:
** file 1
*/

#include "rpg.h"

void anim_player_move(struct_t *store)
{
    if ((store->game->player->speedx > 2 || store->game->player->speedx < -2)
    || (store->game->player->speedy > 2 || store->game->player->speedy < -2)) {
        store->game->player->rec.left += 23;
        if (store->game->player->rec.left >= 230)
            store->game->player->rec.left = 0;
        sfSprite_setTextureRect(store->game->player->sprite,
        store->game->player->rec);
    } else {
        store->game->player->rec.left = 0;
        sfSprite_setTextureRect(store->game->player->sprite,
        store->game->player->rec);
    }
}

void anim_player_atk(struct_t *store)
{
    store->game->player->nb_atk += 1;
    if ((store->game->player->nb_atk == 8 && store->game->player->bow == 0)
    || (store->game->player->nb_atk == 6 && store->game->player->bow == 1)) {
        store->game->player->player_atk_type = 0;
        store->game->player->rec = (sfIntRect) {0, 0, 23, 25};
        store->game->player->nb_atk = 0;
        store->game->player->cooldown.microseconds
        = store->game->clock->master_time.microseconds;
        return;
    }
    if (store->game->player->bow == 0)
        store->game->player->rec.left += 32;
    else
        store->game->player->rec.left += 21;
    sfSprite_setTextureRect(store->game->player->sprite,
        store->game->player->rec);
}

void clock(game_clock_t *clock, struct_t *store)
{
    clock->master_time = sfClock_getElapsedTime(clock->master_clock);
    clock->delta_time.microseconds
    = (clock->master_time.microseconds
    - clock->previous_master_time.microseconds);
    clock->previous_master_time.microseconds = clock->master_time.microseconds;
    clock->anim_time.microseconds += clock->delta_time.microseconds;
    if (clock->anim_time.microseconds >= 150000) {
        while (clock->anim_time.microseconds >= 150000) {
            if (store->game->player->player_atk_type == 0
            && store->game->map->changing_room == 0)
                anim_player_move(store);
            anim_obj(store);
            if (store->game->player->player_atk_type > 0)
                anim_player_atk(store);
            clock->anim_time.microseconds -= 50000;
        }
    }
}

void timer(struct_t *store)
{
    if (store->game->mode == MODE_GAME) {
        if (store->game->clock->time_freeze == 0) {
            sfClock_restart(store->game->clock->master_clock);
            store->game->clock->previous_master_time.microseconds = 0;
            store->game->player->cooldown.microseconds = 0;
            store->game->dialogue->deltatime.microseconds = 0;
            store->game->map->anim_changing_room.microseconds = 0;
            store->game->map->anim_changing_basement.microseconds = 0;
            store->game->clock->time_freeze = 1;
        }
        clock(store->game->clock, store);
    }
    if (store->game->mode == MODE_PAUSE
        && store->game->clock->time_freeze == 1)
        pause_mode(store);
}