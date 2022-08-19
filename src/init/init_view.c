/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** init_view.c
*/

#include "rpg.h"

sfView *set_camera_size(sfView *cam)
{
    sfVector2f size;

    size.x = 1920;
    size.y = 1080;
    sfView_setSize(cam, size);
    return (cam);
}

sfView *load_cam(void)
{
    sfFloatRect size;
    sfView *cam;
    sfVector2f pos;

    size.top = 0;
    size.left = 0;
    size.height = 1920;
    size.width = 1080;
    cam = sfView_createFromRect(size);
    size.height = 1;
    size.width = 1;
    sfView_setViewport(cam, size);
    set_camera_size(cam);
    pos.x = 1920 / 2;
    pos.y = 1080 / 2;
    sfView_setCenter(cam, pos);
    return (cam);
}

void load_mini_maps(struct_t *store)
{
    sfFloatRect size;
    sfVector2f pos;

    size.top = 0;
    size.left = 0;
    size.height = 1920;
    size.width = 1080;
    store->mini_maps = sfView_createFromRect(size);
    size.left = 0.85;
    size.height = 0.15;
    size.width = 0.15;
    sfView_setViewport(store->mini_maps, size);
    sfView_setSize(store->mini_maps, (sfVector2f) {5760, 3240});
    pos.x = 1920 / 2;
    pos.y = 1080 / 2;
    sfView_setCenter(store->mini_maps, pos);
}

void load_hud(struct_t *store)
{
    sfFloatRect size;
    sfVector2f pos;

    size.top = 0;
    size.left = 0;
    size.height = 1920;
    size.width = 1080;
    store->hud = sfView_createFromRect(size);
    size.height = 1;
    size.width = 1;
    sfView_setViewport(store->hud, size);
    sfView_setSize(store->hud, (sfVector2f) {1920, 1080});
    pos.x = 1920 / 2;
    pos.y = 1080 / 2;
    sfView_setCenter(store->hud, pos);
}