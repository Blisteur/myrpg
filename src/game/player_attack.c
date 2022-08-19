/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** player_attack.c
*/

#include "rpg.h"

static sfFloatRect resize_sword(player_t *player, int dir)
{
    sfFloatRect atk = player->hit_box;

    if (dir == 1) {
        atk.top += -50 * player->stats->range;
        atk.height += 50 * player->stats->range;
    } if (dir == 2) {
        atk.top += 100;
        atk.height += 50 * player->stats->range;
    } if (dir == 3) {
        atk.left += -50 * player->stats->range;
        atk.width += 100 * player->stats->range;
        atk.height += 50;
    } if (dir == 4) {
        atk.width += 50 * player->stats->range;
        atk.height += 50;
    }
    return (atk);
}

void hit_with_sword(struct_t *store, player_t *player)
{
    sfFloatRect atk = player->hit_box;
    sfFloatRect old;

    old.left = atk.left;
    old.top = atk.top;
    old.height = atk.height;
    old.width = atk.width;
    atk = resize_sword(player, player->player_atk_type);
    arrow_hitbox(store, atk);
    if (store->game->debug == 1)
        show_hitbox(store, atk);
    player->hit_box = old;
    return;
}