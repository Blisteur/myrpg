/*
** EPITECH PROJECT, 2021
** menu_event
** File description:
** file 2
*/

#include "rpg.h"

void menu_main(struct_t *store)
{
    if (store->menu->selected == 0) {
        write(1, "create new game.\n", 17);
        switch_game_scene(store);
    } if (store->menu->selected == 1) {
        write(1, "charge last game.\n", 18);
    } if (store->menu->selected == 2)
        store->menu->page += 1;
    if (store->menu->selected == 3)
        sfRenderWindow_close(store->win);
    audio_run_sound(store, SOUND_SELECT);
}