/*
** EPITECH PROJECT, 2021
** init_clock
** File description:
** file 1
*/

#include "rpg.h"

void init_clock(game_t *game)
{
    game->clock = malloc(sizeof(game_clock_t));
    game->clock->time_freeze = 0;
    game->clock->anim_time.microseconds = 0;
    game->clock->delta_time.microseconds = 0;
    game->clock->master_clock = sfClock_create();
    game->clock->master_time.microseconds = 0;
    game->clock->previous_master_time.microseconds = 0;
}

void destroy_clock(game_clock_t *clock)
{
    sfClock_destroy(clock->master_clock);
    free(clock);
}