/*
** EPITECH PROJECT, 2021
** init door
** File description:
** file 1
*/

#include "rpg.h"

static void create_door_right_left(struct_t *store, game_room_t *tmp
                                , game_room_t *tmp2)
{
    for (int subnb = 0; subnb < store->game->map->nb_room; subnb += 1) {
        if (sfFloatRect_intersects(&tmp->player_here, &tmp2->player_here,
        NULL) == sfTrue && tmp != tmp2) {
            tmp->first_door = add_room_door(tmp, tmp->first_door,
            (sfVector2f) {tmp->back->pos.x + 1836, tmp->back->pos.y + 440},
            init_right_door);
            tmp2->first_door = add_room_door(tmp2, tmp2->first_door,
            (sfVector2f) {tmp2->back->pos.x + 84, tmp2->back->pos.y + 636},
            init_left_door);
        }
        tmp2 = tmp2->next;
    }
}

static void create_door_donw_up(struct_t *store, game_room_t *tmp
                                , game_room_t *tmp2)
{
    for (int subnb = 0; subnb < store->game->map->nb_room; subnb += 1) {
        if (sfFloatRect_intersects(&tmp->player_here, &tmp2->player_here,
        NULL) == sfTrue && tmp != tmp2) {
            tmp->first_door = add_room_door(tmp, tmp->first_door,
            (sfVector2f) {tmp->back->pos.x + 860, tmp->back->pos.y + 996},
            init_down_door);
            tmp2->first_door = add_room_door(tmp2, tmp2->first_door,
            (sfVector2f) {tmp2->back->pos.x + 860, tmp2->back->pos.y + 84},
            init_up_door);
        }
        tmp2 = tmp2->next;
    }
}

void create_door(struct_t *store)
{
    game_room_t *tmp;
    game_room_t *tmp2;

    tmp = store->game->map->first_room;
    for (int nb = 0; nb < store->game->map->nb_room; nb += 1) {
        tmp->player_here.left += 1;
        tmp2 = store->game->map->first_room;
        create_door_right_left(store, tmp, tmp2);
        tmp->player_here.left -= 1;
        tmp->player_here.top += 1;
        tmp2 = store->game->map->first_room;
        create_door_donw_up(store, tmp, tmp2);
        tmp->player_here.top -= 1;
        tmp = tmp->next;
    }
}