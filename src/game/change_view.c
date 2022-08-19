/*
** EPITECH PROJECT, 2021
** view_handler
** File description:
** file 2
*/

#include "rpg.h"

void change_view(struct_t *store, int x, int y)
{
    sfView_move(store->cam, (sfVector2f) {x, y});
    sfView_move(store->mini_maps, (sfVector2f) {x, y});
}