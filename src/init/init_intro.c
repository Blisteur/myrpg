/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** init_intro.c
*/

#include "rpg.h"

void init_intro(struct_t *store)
{
    store->intro = malloc(sizeof(intro_t));
    store->intro->back = create_elem("src/files/game/intro.png", vec(0, 0),
    rect(0, 0, 960, 540), 2);
    store->intro->text = create_elem("src/files/game/intro.png", vec(256, 306),
    rect(961, 0, 704, 234), 2);
    store->intro->wait = 0;
    store->intro->state = 1;
    store->intro->time = 0;
    intro_audio(store, 1);
}

void destroy_intro(struct_t *store)
{
    intro_audio(store, 2);
    sfClock_restart(store->game->clock->master_clock);
    store->game->clock->previous_master_time.microseconds = 0;
    destroy_elem(store->intro->back);
    destroy_elem(store->intro->text);
    free(store->intro);
}