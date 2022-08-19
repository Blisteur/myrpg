/*
** EPITECH PROJECT, 2020
** B-MUL-200-NCY-2-1-myrpg-nathan.chiodin
** File description:
** player_move_dir.c
*/

#include "rpg.h"

void player_move_up(struct_t *store, player_t *player)
{
    if (player->speedy > 0)
        player->speedy -= player->stats->speed / 4;
    player->speedy -= player->stats->speed / 2;
    store->game->player->rec.top = 75;
}

void player_move_down(struct_t *store, player_t *player)
{
    if (player->speedy < 0)
        player->speedy += player->stats->speed / 4;
    player->speedy += player->stats->speed / 2;
    store->game->player->rec.top = 0;
}

void player_move_left(struct_t *store, player_t *player)
{
    if (player->speedx > 0)
        player->speedx -= player->stats->speed / 4;
    player->speedx -= player->stats->speed / 2;
    store->game->player->rec.top = 25;
}

void player_move_right(struct_t *store, player_t *player)
{
    if (player->speedx < 0)
        player->speedx += player->stats->speed / 4;
    player->speedx += player->stats->speed / 2;
    store->game->player->rec.top = 50;
}