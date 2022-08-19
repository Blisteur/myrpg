/*
** EPITECH PROJECT, 2021
** init_struct
** File description:
** file 1
*/

#include "rpg.h"

void set_struct(struct_t *store)
{
    store->cam = load_cam();
    sfRenderWindow_setView(store->win, store->cam);
    init_audio(store);
}

void init_struct(struct_t *store)
{
    store->settings = malloc(sizeof(settings_t));
    init_settings(store);
    if (store->settings->fullscreen == 0)
        store->win = sfRenderWindow_create(store->settings->video_mode
                                    , "MY_RPG", sfResize | sfClose, NULL);
    else
        store->win = sfRenderWindow_create(store->settings->video_mode
                                    , "MY_RPG", sfFullscreen, NULL);
    set_struct(store);
    sfRenderWindow_setFramerateLimit(store->win, store->settings->fps);
}

void destroy_struct(struct_t *store)
{
    if (store->settings->is_modified == 1) {
        write_settings(store);
        write_inputs(store);
    }
    sfRenderWindow_destroy(store->win);
    sfView_destroy(store->cam);
    destroy_audio(store);
    free(store->settings);
    free(store);
}