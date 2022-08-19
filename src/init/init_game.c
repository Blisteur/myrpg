/*
** EPITECH PROJECT, 2021
** init game
** File description:
** file 1
*/

#include "rpg.h"

static void inputs_ptr(struct_t *store)
{
    store->game->inputs_ptr[0] = player_move_up;
    store->game->inputs_ptr[1] = player_move_down;
    store->game->inputs_ptr[2] = player_move_left;
    store->game->inputs_ptr[3] = player_move_right;
    store->game->inputs_ptr[4] = player_fire_up;
    store->game->inputs_ptr[5] = player_fire_down;
    store->game->inputs_ptr[6] = player_fire_left;
    store->game->inputs_ptr[7] = player_fire_right;
    store->game->inputs_ptr[8] = player_bow;
    store->game->inputs_ptr[9] = player_bomb;
    for (int nb = 0; nb < 10; nb += 1)
        store->game->inputs_presed[nb] = 0;
}

void init_pause(struct_t *store)
{
    store->game->pause = malloc(sizeof(pause_t));
    store->game->pause->selected = 0;
    store->game->pause->pause = create_elem("src/files/game/pause.png",
    vec(0, 0), rect(0, 0, 480, 270), 4);
    store->game->pause->select = create_elem("src/files/menu/select.png",
    vec(0, 0), rect(0, 0, 12, 15), 4);
}

void destroy_pause(struct_t *store)
{
    destroy_elem(store->game->pause->pause);
    destroy_elem(store->game->pause->select);
    free(store->game->pause);
}

void init_game(struct_t *store)
{
    store->game = malloc(sizeof(game_t));
    store->game->stop = 0;
    store->game->mode = MODE_GAME;
    store->game->debug = 0;
    init_clock(store->game);
    game_audio(store, 1);
    inputs_ptr(store);
    init_player(store);
    load_mini_maps(store);
    load_hud(store);
    init_map(store);
    init_hud(store);
    init_dialogue(store);
    init_pause(store);
    init_particles(store);
}

void destroy_game(struct_t *store)
{
    destroy_particles(store);
    destroy_clock(store->game->clock);
    game_audio(store, 2);
    destroy_player(store);
    destroy_map(store);
    sfView_destroy(store->mini_maps);
    sfView_destroy(store->hud);
    destroy_hud(store);
    destroy_dialogue(store);
    destroy_pause(store);
    free(store->game);
    sfView_setSize(store->cam, (sfVector2f) {1920, 1080});
}