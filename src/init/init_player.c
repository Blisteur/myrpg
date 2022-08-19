/*
** EPITECH PROJECT, 2021
** init_player
** File description:
** file 1
*/

#include "rpg.h"

static void init_player_stats(player_t *player)
{
    player->stats = malloc(sizeof(struct stats_s));
    player->stats->def = 0;
    player->stats->cur_hp = 6;
    player->stats->max_hp = 6;
    player->stats->extra_hp = 0;
    player->stats->atk = 3.0;
    player->stats->atk_spd = 3.0;
    player->stats->range = 1.0;
    player->stats->speed = 3.0;
    player->stats->grace = 0.0;
    player->stats->exp = 0;
    player->stats->max_exp = 3;
}

static void init_player_var(struct_t *store)
{
    store->game->player->player_bomb = NULL;
    store->game->player->player_arrows = NULL;
    store->game->player->bow = 0;
    store->game->player->bomb = 1;
    store->game->player->nb_arrows = 0;
    store->game->player->key = 0;
    store->game->player->life = 100;
    store->game->player->money = 0;
    store->game->player->pos = (sfVector2f) {0, 0};
    store->game->player->rec = (sfIntRect) {0, 0, 23, 25};
    store->game->player->speedx = 0.0;
    store->game->player->speedy = 0.0;
    store->game->player->cooldown.microseconds = 0;
    store->game->player->player_atk_type = 0;
    store->game->player->nb_atk = 0;
    store->game->player->room_id = 0;
}

void init_player(struct_t *store)
{
    store->game->player = malloc(sizeof(player_t));
    init_player_var(store);
    store->game->player->sprite = sfSprite_create();
    store->game->player->texture
    = sfTexture_createFromFile("src/files/game/link.png", NULL);
    sfSprite_setTexture(store->game->player->sprite,
    store->game->player->texture, sfFalse);
    sfSprite_setTextureRect(store->game->player->sprite
    , store->game->player->rec);
    sfSprite_setPosition(store->game->player->sprite
    , store->game->player->pos);
    sfSprite_scale(store->game->player->sprite, (sfVector2f) {4, 4});
    init_player_stats(store->game->player);
    store->game->player->hit_box = (sfFloatRect)
    {store->game->player->pos.x, store->game->player->pos.y, 90 - 28, 95 - 50};
}

void destroy_player(struct_t *store)
{
    if (store->game->player->player_bomb != NULL) {
        destroy_elem(store->game->player->player_bomb->bomb);
        free(store->game->player->player_bomb);
    }
    sfTexture_destroy(store->game->player->texture);
    sfSprite_destroy(store->game->player->sprite);
    remove_all_arrows(store->game->player);
    free(store->game->player->stats);
    free(store->game->player);
}