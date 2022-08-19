/*
** EPITECH PROJECT, 2021
** player event
** File description:
** file 1
*/

#include "rpg.h"

void player_events(struct_t *store)
{
    for (int nb = 0; nb < 10; nb += 1) {
        if (sfKeyboard_isKeyPressed(store->settings->inputs[nb]) == sfTrue) {
            store->game->inputs_ptr[nb](store, store->game->player);
            store->game->inputs_presed[nb] = 1;
        }
    }
}