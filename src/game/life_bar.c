/*
** EPITECH PROJECT, 2020
** B-MUL-200-NCY-2-1-myrpg-nathan.chiodin
** File description:
** life_bar.c
*/

#include "rpg.h"

void display_hearts(struct_t *store, game_text_t *hud, sfVector2f pos)
{
    int max = store->game->player->stats->max_hp;
    int cur = store->game->player->stats->cur_hp;

    for (; max > 0; max = max - 2) {
        sfSprite_setPosition(hud->hpbar, pos);
        if (cur <= 1) {
            hud->rect.left = 7;
            sfSprite_setTextureRect(hud->hpbar, hud->rect);
        }
        if (cur <= 0) {
            hud->rect.left = 14;
            sfSprite_setTextureRect(hud->hpbar, hud->rect);
        }
        sfRenderWindow_drawSprite(store->win, hud->hpbar, NULL);
        cur = cur - 2;
        pos.x = pos.x + 48;
    }
}

void display_health(struct_t *store, game_text_t *hud)
{
    sfVector2f pos = sfView_getCenter(store->hud);

    pos.x -= 900;
    pos.y -= 500;
    display_hearts(store, hud, pos);
    hud->rect.left = 0;
    sfSprite_setTextureRect(hud->hpbar, hud->rect);
}