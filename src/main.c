/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** file 1
*/

#include "rpg.h"

static void game(void)
{
    struct_t *store = malloc(sizeof(struct_t));

    init_struct(store);
    init_menu(store);
    while (sfRenderWindow_isOpen(store->win)) {
        sfRenderWindow_display(store->win);
        menu(store);
        menu_event(store);
    }
    destroy_menu(store);
    destroy_struct(store);
}

int main(void)
{
    game();
    return (0);
}