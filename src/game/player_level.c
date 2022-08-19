/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** player_level.c
*/

#include "rpg.h"

void level_up(struct_t *store)
{
    player_t *player = store->game->player;

    player->stats->max_hp += 2;
    player->stats->cur_hp += 2;
    player->stats->atk += 1;
    player->stats->atk_spd += 0.5;
    player->stats->speed += 0.15;
    player->stats->range += 0.25;
    player->stats->exp = 0;
    player->stats->max_exp += 3;
    update_txt_stats((int) (store->game->player->stats->atk)
    , store->game->game_text->stats[0], "ATK");
    update_txt_stats((int) (store->game->player->stats->atk_spd)
    , store->game->game_text->stats[1], "ATS");
    update_txt_stats((int) (store->game->player->stats->range)
    , store->game->game_text->stats[2], "RNG");
    update_txt_stats((int) (store->game->player->stats->speed)
    , store->game->game_text->stats[3], "SPD");
    update_txt_stats(store->game->player->stats->def
    , store->game->game_text->stats[4], "DEF");
}

void heal_player(struct_t *store)
{
    player_t *player = store->game->player;

    player->stats->cur_hp = player->stats->max_hp;
}