/*
** EPITECH PROJECT, 2021
** door
** File description:
** file 1
*/

#include "rpg.h"

static void close_door_room(game_room_t *tmp
                , game_room_door_t *tmp3)
{
    tmp->lock = 1;
    for (int subnb = 0; subnb < tmp->nb_door; subnb += 1) {
        tmp3->plain->rect.left = 98;
        sfSprite_setTextureRect(tmp3->plain->spr, tmp3->plain->rect);
        tmp3 = tmp3->next;
    }
}

static void open_door_room(game_room_t *tmp
                , game_room_door_t *tmp3)
{
    tmp->lock = 0;
    for (int subnb = 0; subnb < tmp->nb_door; subnb += 1) {
        tmp3->plain->rect.left = 49;
        sfSprite_setTextureRect(tmp3->plain->spr, tmp3->plain->rect);
        tmp3 = tmp3->next;
    }
}

void door_handler(game_room_t *tmp
                , game_room_door_t *tmp3, int mob)
{
    if ((tmp->lock == 0 && mob == 0) || tmp->seed == 1)
        return;
    if (mob == 0)
        open_door_room(tmp, tmp3);
    else
        close_door_room(tmp, tmp3);
    tmp3 = tmp->first_door;
}