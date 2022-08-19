/*
** EPITECH PROJECT, 2021
** destroy map
** File description:
** file 1
*/

#include "rpg.h"

void destroy_map(struct_t *store)
{
    remove_all_room(store);
    free(store->game->map);
}