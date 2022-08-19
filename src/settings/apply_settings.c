/*
** EPITECH PROJECT, 2021
** apply settings
** File description:
** file 1
*/

#include "rpg.h"

void apply_settings(struct_t *store)
{
    sfRenderWindow_destroy(store->win);
    if (store->settings->fullscreen == 0)
        store->win = sfRenderWindow_create(store->settings->video_mode,
                                    "MY_RPG", sfResize | sfClose, NULL);
    else
        store->win = sfRenderWindow_create(store->settings->video_mode,
                                    "MY_RPG", sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(store->win, store->settings->fps);
    sfRenderWindow_setView(store->win, store->cam);
}