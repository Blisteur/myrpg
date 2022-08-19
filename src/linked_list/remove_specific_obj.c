/*
** EPITECH PROJECT, 2021
** remove obj
** File description:
** file 1
*/

#include "rpg.h"

static void remove_stats_mob(object_t *p)
{
    if (p->id == OBJ_MOB1 || p->id == OBJ_MOB2 || p->id == OBJ_MOB3)
        free(p->stats);
}

void remove_spe_obj(object_t *p, game_room_t *room)
{
    object_t *tmp = room->first_object;

    if (tmp == p) {
        room->first_object = tmp->next;
        room->nb_object -= 1;
        remove_stats_mob(p);
        destroy_elem(p->obj);
        free(p);
        return;
    }
    for (int nb = 0; nb < room->nb_object; nb += 1) {
        if (tmp->next == p) {
            tmp->next = tmp->next->next;
            room->nb_object -= 1;
            remove_stats_mob(p);
            destroy_elem(p->obj);
            free(p);
        }
        tmp = tmp->next;
    }
}