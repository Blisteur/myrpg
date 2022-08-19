/*
** EPITECH PROJECT, 2021
** view handler
** File description:
** file 1
*/

#include "rpg.h"

static void change_room_hiding(struct_t *store)
{
    game_room_t *tmp = store->game->map->first_room;

    for (int nb = 0; nb < store->game->map->nb_room; nb += 1) {
        if (sfFloatRect_intersects(&store->game->player->hit_box,
        &tmp->player_here, NULL) == sfTrue) {
            tmp->hide = 1;
            store->game->player->room_id = tmp->id;
        }
        tmp = tmp->next;
    }
}

static void change_view_parser(struct_t *store, char d)
{
    if (d == 'u')
        change_view(store, 0, -27);
    if (d == 'd')
        change_view(store, 0, 27);
    if (d == 'l')
        change_view(store, -48, 0);
    if (d == 'r')
        change_view(store, 48, 0);
}

void trans_view_room(struct_t *store, char d)
{
    store->game->map->anim_changing_room.microseconds
    += store->game->clock->delta_time.microseconds;
    if (store->game->map->anim_changing_room.microseconds > 25000) {
        if (store->game->map->changing_room == 1)
            change_room_hiding(store);
        if (store->game->map->changing_room == 41) {
            store->game->map->changing_room = 0;
            store->game->map->anim_changing_room.microseconds = 0;
            remove_all_arrows(store->game->player);
            return;
        }
        change_view_parser(store, d);
        store->game->map->changing_room += 1;
        store->game->map->anim_changing_room.microseconds = 0;
    }
}

void trans_view_basement_zoom(struct_t *store)
{
    store->game->map->anim_changing_basement.microseconds
    += store->game->clock->delta_time.microseconds;
    if (store->game->map->anim_changing_basement.microseconds > 25000) {
        if (store->game->map->changing_basement == -41) {
            store->game->map->changing_basement = 0;
            store->game->map->anim_changing_basement.microseconds = 0;
            remove_all_arrows(store->game->player);
            change_basement(store);
            return;
        }
        store->game->map->zoom_basement.x -= 48;
        store->game->map->zoom_basement.y -= 27;
        sfView_setSize(store->cam, store->game->map->zoom_basement);
        store->game->map->changing_basement -= 1;
        store->game->map->anim_changing_basement.microseconds = 0;
    }
}

void trans_view_basement_unzoom(struct_t *store)
{
    store->game->map->anim_changing_basement.microseconds
    += store->game->clock->delta_time.microseconds;
    if (store->game->map->anim_changing_basement.microseconds > 25000) {
        if (store->game->map->changing_basement == 41) {
            store->game->map->changing_basement = 0;
            store->game->map->anim_changing_basement.microseconds = 0;
            sfView_setSize(store->cam, (sfVector2f) {1920, 1080});
            return;
        }
        store->game->map->zoom_basement.x += 48;
        store->game->map->zoom_basement.y += 27;
        sfView_setSize(store->cam, store->game->map->zoom_basement);
        store->game->map->changing_basement += 1;
        store->game->map->anim_changing_basement.microseconds = 0;
    }
}