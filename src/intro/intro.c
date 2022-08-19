/*
** EPITECH PROJECT, 2021
** intro
** File description:
** intro
*/

#include "rpg.h"

static void display_intro(struct_t *store)
{
    sfRenderWindow_drawSprite(store->win, store->intro->back->spr, NULL);
    sfRenderWindow_drawSprite(store->win, store->intro->text->spr, NULL);
    sfRenderWindow_display(store->win);
}

static void analyse_events_intro(struct_t *store)
{
    while (sfRenderWindow_pollEvent(store->win, &store->evt)) {
        if (store->evt.type == sfEvtClosed)
            sfRenderWindow_close(store->win);
        if (store->evt.key.type == sfEvtKeyReleased)
            store->intro->state = 0;
    }
}

void intro_loop(struct_t *store)
{
    audio_run_music(store, MUSIC_INTRO);
    while (store->intro->state != 0 && sfRenderWindow_isOpen(store->win)) {
        clock_intro(store->game->clock, store);
        display_intro(store);
        analyse_events_intro(store);
    }
    sfMusic_stop(store->audio->master_music[MUSIC_INTRO]);
}