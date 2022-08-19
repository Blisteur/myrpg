/*
** EPITECH PROJECT, 2021
** room_list
** File description:
** file 1
*/

#include "rpg.h"

game_room_door_t *add_room_door(game_room_t *room, game_room_door_t *p
                    , sfVector2f pos, void *seed)
{
    game_room_door_t *list = malloc(sizeof(game_room_door_t));
    void(*ptr)(game_room_door_t *, sfVector2f);

    ptr = seed;
    ptr(list, pos);
    list->next = p;
    p = list;
    room->nb_door += 1;
    return (list);
}

void remove_room_door_link(game_room_door_t *p, game_room_t *room)
{
    if (p == room->first_door)
        room->first_door = p->next;
    room->nb_door -= 1;
    destroy_elem(p->back);
    destroy_elem(p->plain);
    free(p);
}