/*
** EPITECH PROJECT, 2021
** menu
** File description:
** menu
*/

#include "rpg.h"

void menu_draw_settings(struct_t *store)
{
    sfRenderWindow_drawSprite(store->win, store->menu->opt->options->spr,
    NULL);
    sfRenderWindow_drawSprite(store->win, store->menu->opt->select->spr,
    NULL);
    sfRenderWindow_drawSprite(store->win, store->menu->opt->res->spr,
    NULL);
    sfRenderWindow_drawSprite(store->win, store->menu->opt->full_on->spr,
    NULL);
    sfRenderWindow_drawSprite(store->win, store->menu->opt->mus_bar->spr,
    NULL);
    sfRenderWindow_drawSprite(store->win, store->menu->opt->sfx_bar->spr,
    NULL);
}

void menu(struct_t *store)
{
    if (store->menu->page == 0) {
        sfRenderWindow_drawSprite(store->win, store->menu->main->spr, NULL);
        sfRenderWindow_drawSprite(store->win, store->menu->logo->spr, NULL);
    } if (store->menu->page == 1) {
        sfRenderWindow_drawSprite(store->win, store->menu->menu->spr, NULL);
        sfRenderWindow_drawSprite(store->win, store->menu->select->spr, NULL);
    } if (store->menu->page == 2) {
        menu_draw_settings(store);
        if (store->menu->opt->istuto == 1)
            sfRenderWindow_drawSprite(store->win, store->menu->opt->tuto->spr,
            NULL);
    } if (store->menu->page == 3) {
        sfRenderWindow_drawSprite(store->win,
        store->menu->contr->controls->spr, NULL);
        sfRenderWindow_drawSprite(store->win, store->menu->contr->select->spr,
        NULL);
        for (int nb = 0; nb < 10; nb += 1)
            sfRenderWindow_drawText(store->win,
            store->menu->contr->key[nb], NULL);
    }
}