/*
** EPITECH PROJECT, 2021
** calcul func
** File description:
** file 1
*/

#include "rpg.h"

float get_distance(struct_t *store, float speed)
{
    float distance = 0;

    distance = speed * 50 * sfTime_asSeconds(store->game->clock->delta_time);
    return (distance);
}