/*
** EPITECH PROJECT, 2021
** switch game scene
** File description:
** file 1
*/

#include "rpg.h"

void switch_game_scene(struct_t *store)
{
    destroy_menu(store);
    init_game(store);
    init_intro(store);
    intro_loop(store);
    destroy_intro(store);
    game_loop(store);
    destroy_game(store);
    sfView_setCenter(store->cam, (sfVector2f) {1920 / 2, 1080 / 2});
    sfRenderWindow_setView(store->win, store->cam);
    init_menu(store);
}