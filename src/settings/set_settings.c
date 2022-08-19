/*
** EPITECH PROJECT, 2021
** set_settings
** File description:
** file 1
*/

#include "rpg.h"

void set_resolution(struct_t *store, char *buff)
{
    int parsing = 0;

    for (; buff[parsing] != '\n'; parsing += 1) {
        if (buff[parsing] == '{')
            store->settings->resolution[0] = my_getnbr(buff + parsing + 1);
        if (buff[parsing] == '*') {
            store->settings->resolution[1] = my_getnbr(buff + parsing + 1);
            break;
        }
    }
    if (store->settings->resolution[0] <= 0 ||
        store->settings->resolution[1] <= 0 ||
        store->settings->resolution[0] > 1920 ||
        store->settings->resolution[1] > 1080) {
        store->settings->resolution[0] = 600;
        store->settings->resolution[1] = 600;
    }
    store->settings->video_mode.width = store->settings->resolution[0];
    store->settings->video_mode.height = store->settings->resolution[1];
}

void set_fullsreen(struct_t *store, char *buff)
{
    int parsing = 0;

    for (; buff[parsing] != '\n'; parsing += 1) {
        if (buff[parsing] == '/' && buff[parsing + 1] == '/')
            break;
        if (buff[parsing] == '{') {
            store->settings->fullscreen = my_getnbr(buff + parsing + 1);
            break;
        }
    }
    if (store->settings->fullscreen != 0 && store->settings->fullscreen != 1) {
        store->settings->fullscreen = 0;
    }
}

void set_bpp(struct_t *store, char *buff)
{
    int parsing = 0;

    for (; buff[parsing] != '\n'; parsing += 1) {
        if (buff[parsing] == '/' && buff[parsing + 1] == '/')
            break;
        if (buff[parsing] == '{') {
            store->settings->bpp = my_getnbr(buff + parsing + 1);
            break;
        }
    }
    if (store->settings->bpp == 0)
        store->settings->bpp = 32;
    store->settings->video_mode.bitsPerPixel = store->settings->bpp;
}

void set_fps(struct_t *store, char *buff)
{
    int parsing = 0;

    for (; buff[parsing] != '\n'; parsing += 1) {
        if (buff[parsing] == '/' && buff[parsing + 1] == '/')
            break;
        if (buff[parsing] == '{') {
            store->settings->fps = my_getnbr(buff + parsing + 1);
            break;
        }
    }
    if (store->settings->fps == 0)
        store->settings->fps = 64;
}