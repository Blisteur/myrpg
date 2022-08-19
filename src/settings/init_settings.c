/*
** EPITECH PROJECT, 2021
** init_settings
** File description:
** file 1
*/

#include "rpg.h"

static void setup_settings_ptr(struct_t *store)
{
    store->settings->ptr[0] = set_resolution;
    store->settings->ptr[1] = set_fullsreen;
    store->settings->ptr[2] = set_bpp;
    store->settings->ptr[3] = set_fps;
    store->settings->ptr[4] = set_master_volume;
    store->settings->ptr[5] = set_sound_volume;
}

void init_settings(struct_t *store)
{
    store->settings->video_mode.width = 0;
    store->settings->video_mode.height = 0;
    store->settings->video_mode.bitsPerPixel = 0;
    store->settings->resolution[0] = 0;
    store->settings->resolution[1] = 0;
    store->settings->fullscreen = 0;
    store->settings->fps = 0;
    store->settings->bpp = 0;
    store->settings->volume[0] = 0;
    store->settings->volume[1] = 0;
    store->settings->is_modified = 0;
    setup_settings_ptr(store);
    get_settings(store);
    get_inputs(store);
    print_active_param(store);
}