/*
** EPITECH PROJECT, 2021
** basement
** File description:
** test
*/

#include "rpg.h"

void change_basement_anim(struct_t *store)
{
    store->game->map->changing_basement = -1;
    heal_player(store);
}

static void dialogue_basement(struct_t *store)
{
    if (store->game->map->level == 2)
        store->game->dialogue->pnj_txt = 2;
    if (store->game->map->level == 3)
        store->game->dialogue->pnj_txt = 5;
}

void change_basement(struct_t *store)
{
    game_room_t *tmp = NULL;
    char tmp_txt[] = "src/files/maps/room1.txt";

    remove_all_room(store);
    store->game->map->level += 1;
    dialogue_basement(store);
    store->game->map->changing_room = 0;
    store->game->map->anim_changing_room.microseconds = 0;
    store->game->map->changin_room_pos = '0';
    create_level(store);
    create_door(store);
    tmp = store->game->map->first_room;
    for (int nb = 0; nb < store->game->map->nb_room; nb += 1) {
        tmp_txt[19] = (tmp->seed + '0');
        read_map(tmp_txt, tmp);
        tmp = tmp->next;
    }
    store->game->map->zoom_basement = (sfVector2f) {0, 0};
    sfView_setSize(store->cam, store->game->map->zoom_basement);
    store->game->map->changing_basement = 1;
}