/*
** EPITECH PROJECT, 2021
** debug
** File description:
** file 1
*/

#include "rpg.h"

void print_active_param(struct_t *store)
{
    my_printf("/////////////////////////\n");
    my_printf("resolution: %dx%d\n", store->settings->resolution[0]
                                    , store->settings->resolution[1]);
    my_printf("fullscreen: %d\n", store->settings->fullscreen);
    my_printf("bpp: %d\n", store->settings->bpp);
    my_printf("fps: %d\n", store->settings->fps);
    my_printf("master volume: %d\n", store->settings->volume[0]);
    my_printf("sound volume: %d\n", store->settings->volume[1]);
    for (int nb = 0; nb < 10; nb += 1) {
        my_printf("input %d: %d\n", nb, store->settings->inputs[nb]);
    }
    my_printf("/////////////////////////\n");
}

void show_hitbox(struct_t *store, sfFloatRect hitbox)
{
    sfRectangleShape *sqare = sfRectangleShape_create();

    sfRenderWindow_setView(store->win, store->cam);
    sfRectangleShape_setSize(sqare
    , (sfVector2f) {hitbox.width, hitbox.height});
    sfRectangleShape_setPosition(sqare
    , (sfVector2f) {hitbox.left, hitbox.top});
    sfRenderWindow_drawRectangleShape(store->win, sqare, NULL);
    sfRenderWindow_display(store->win);
    sfRectangleShape_destroy(sqare);
}