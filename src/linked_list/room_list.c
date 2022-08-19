/*
** EPITECH PROJECT, 2021
** room_list
** File description:
** file 1
*/

#include "rpg.h"

object_t *add_room_object(game_room_t *room, object_t *p
                    , sfVector2f pos, void *seed)
{
    object_t *list = malloc(sizeof(object_t));
    void(*ptr)(object_t *, sfVector2f);

    ptr = seed;
    ptr(list, pos);
    if (room->first_object == NULL)
        room->first_object = list;
    else
        p->next = list;
    list->next = NULL;
    room->nb_object += 1;
    return (list);
}

void remove_room_object_link(object_t *p, game_room_t *room)
{
    if (p == room->first_object)
        room->first_object = p->next;
    room->nb_object -= 1;
    if (p->id == OBJ_MOB1 || p->id == OBJ_MOB2 || p->id == OBJ_MOB3)
        free(p->stats);
    destroy_elem(p->obj);
    free(p);
}

game_room_t *add_room(struct_t *store, game_room_t *p
                    , sfVector2f pos, void *seed)
{
    game_room_t *list = malloc(sizeof(game_room_t));
    void(*ptr)(game_room_t *, sfVector2f);

    ptr = seed;
    ptr(list, pos);
    list->next = p;
    p = list;
    store->game->map->nb_room += 1;
    p->id = store->game->map->nb_room;
    p->nb_object = 0;
    p->nb_door = 0;
    p->first_object = NULL;
    p->first_door = NULL;
    return (list);
}

void remove_room_link(struct_t *store, game_room_t *p)
{
    if (p == store->game->map->first_room)
        store->game->map->first_room = p->next;
    store->game->map->nb_room -= 1;
    destroy_elem(p->back);
    free(p);
}

void remove_all_room(struct_t *store)
{
    game_room_t *tmp = store->game->map->first_room;

    while (store->game->map->nb_room != 0) {
        while (tmp->nb_object != 0) {
            remove_room_object_link(tmp->first_object, tmp);
        }
        while (tmp->nb_door != 0) {
            remove_room_door_link(tmp->first_door, tmp);
        }
        remove_room_link(store, store->game->map->first_room);
        tmp = store->game->map->first_room;
    }
    store->game->map->first_room = NULL;
}