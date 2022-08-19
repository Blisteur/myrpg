/*
** EPITECH PROJECT, 2021
** game
** File description:
** file 1
*/

#include "rpg.h"

static void display_handler(struct_t *store)
{
    if (store->game->mode == MODE_GAME) {
        if (store->game->map->changing_room > 0)
            trans_view_room(store, store->game->map->changin_room_pos);
        if (store->game->map->changing_basement < 0)
            trans_view_basement_zoom(store);
        if (store->game->map->changing_basement > 0)
            trans_view_basement_unzoom(store);
        sfRenderWindow_setView(store->win, store->cam);
        display_game(store);
        sfRenderWindow_setView(store->win, store->mini_maps);
        display_game(store);
        display_game_hud(store);
        if (store->game->dialogue->lock == 1) {
            diag_time_out(store);
        }
    }
    if (store->game->mode == MODE_PAUSE)
        display_pause(store->win, store);
    sfRenderWindow_display(store->win);
}

static void input_minimap(struct_t *store)
{
    if (store->evt.key.code == sfKeyTab) {
        if (store->evt.type == sfEvtKeyPressed) {
            sfView_setViewport(store->mini_maps
            , (sfFloatRect) {0.25, 0.25, 0.5, 0.5});
            sfView_setSize(store->mini_maps
            , (sfVector2f) {9600, 5400});
        }
        if (store->evt.type == sfEvtKeyReleased) {
            sfView_setViewport(store->mini_maps
            , (sfFloatRect) {0.85, 0, 0.15, 0.15});
            sfView_setSize(store->mini_maps
            , (sfVector2f) {5760, 3240});
        }
    }
}

static void analyse_events_game(struct_t *store)
{
    while (sfRenderWindow_pollEvent(store->win, &store->evt)) {
        if (store->evt.type == sfEvtClosed)
            sfRenderWindow_close(store->win);
        if (store->evt.key.code == sfKeyBackspace
        && store->evt.type == sfEvtKeyReleased)
            store->game->stop = 1;
        pause_event(store);
        input_minimap(store);
    }
    if (store->game->mode == MODE_GAME && store->game->map->changing_room == 0
        && store->game->player->player_atk_type == 0) {
        player_move(store, store->game->player);
        player_events(store);
        obj_move(store);
    }
    if (store->game->player->stats->cur_hp <= 0)
        store->game->stop = 1;
}

void game_loop(struct_t *store)
{
    audio_run_music(store, MUSIC_TYPE1);
    while (store->game->stop == 0 && sfRenderWindow_isOpen(store->win)) {
        timer(store);
        display_handler(store);
        analyse_events_game(store);
    }
}