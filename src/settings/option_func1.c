/*
** EPITECH PROJECT, 2021
** option func
** File description:
** file 1
*/

#include "rpg.h"

void change_fps(struct_t *store, int fps)
{
    store->settings->fps = fps;
    store->settings->is_modified = 1;
    apply_settings(store);
    print_active_param(store);
}

void change_master_vl(struct_t *store, int mode)
{
    if (mode == 1) {
        store->settings->volume[0] += 10;
        if (store->settings->volume[0] > 100)
            store->settings->volume[0] = 100;
    } else {
        store->settings->volume[0] -= 10;
        if (store->settings->volume[0] < 0)
            store->settings->volume[0] = 0;
    }
    store->settings->is_modified = 1;
    sfMusic_setVolume(store->audio->master_music[MUSIC_MENU]
    , store->settings->volume[0]);
    print_active_param(store);
}

void change_sound_vl(struct_t *store, int mode)
{
    if (mode == 1) {
        store->settings->volume[1] += 10;
        if (store->settings->volume[1] > 100)
            store->settings->volume[1] = 100;
    } else {
        store->settings->volume[1] -= 10;
        if (store->settings->volume[1] < 0)
            store->settings->volume[1] = 0;
    }
    store->settings->is_modified = 1;
    print_active_param(store);
    sfSound_setVolume(store->audio->master_sound[SOUND_CURSOR]
    , store->settings->volume[1]);
    sfSound_setVolume(store->audio->master_sound[SOUND_SELECT]
    , store->settings->volume[1]);
}

void change_fullscreen(struct_t *store)
{
    if (store->settings->fullscreen == 0)
        store->settings->fullscreen = 1;
    else
        store->settings->fullscreen = 0;
    store->settings->is_modified = 1;
    apply_settings(store);
    print_active_param(store);
}

void change_resolution(struct_t *store, int mode)
{
    if (mode == 0) {
        store->settings->resolution[0] = 1920;
        store->settings->resolution[1] = 1080;
    }
    if (mode == 1) {
        store->settings->resolution[0] = 1280;
        store->settings->resolution[1] = 720;
    }
    if (mode == 2) {
        store->settings->resolution[0] = 800;
        store->settings->resolution[1] = 600;
    }
    store->settings->video_mode.width = store->settings->resolution[0];
    store->settings->video_mode.height = store->settings->resolution[1];
    store->settings->is_modified = 1;
    apply_settings(store);
    print_active_param(store);
}