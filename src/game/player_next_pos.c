/*
** EPITECH PROJECT, 2021
** player_next_pos
** File description:
** file 2
*/

#include "rpg.h"

void get_player_next_pos(struct_t *store, player_t *player, float posy)
{
    float posx = 0;
    sfFloatRect tmpx = {0, 0, player->hit_box.width, player->hit_box.height};
    sfFloatRect tmpy = {0, 0, player->hit_box.width, player->hit_box.height};

    posy = get_distance(store, player->speedy);
    posx = get_distance(store, player->speedx);
    tmpx.left = player->hit_box.left + posx + 16;
    tmpx.top = player->hit_box.top + 45;
    tmpy.left = player->hit_box.left + 16;
    tmpy.top = player->hit_box.top + posy + 45;
    if (get_hitbox(store, tmpx) == 1) {
        player->speedx = 0;
        posx = 0;
    }
    if (get_hitbox(store, tmpy) == 1) {
        player->speedy = 0;
        posy = 0;
    }
    player->pos.y += posy;
    player->pos.x += posx;
}