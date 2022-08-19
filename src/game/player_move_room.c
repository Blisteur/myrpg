/*
** EPITECH PROJECT, 2021
** player move
** File description:
** file 1
*/

#include "rpg.h"

static void move_room_change_pos(struct_t *store, int dirx, int diry)
{
    store->game->player->pos.y = diry;
    store->game->player->pos.x = dirx;
    store->game->player->speedx = 0;
    store->game->player->speedy = 0;
}

static void move_room_get(struct_t *store, game_room_door_t *door, char dir)
{
    switch (dir) {
        case 'u':
            move_room_change_pos(store, door->hit_box.left + 8,
            store->game->player->pos.y - 500);
            break;
        case 'd':
            move_room_change_pos(store, door->hit_box.left + 8,
            store->game->player->pos.y + 500);
            break;
        case 'r':
            move_room_change_pos(store, store->game->player->pos.x + 500,
            door->hit_box.top - 24);
            break;
        case 'l':
            move_room_change_pos(store, store->game->player->pos.x - 500,
            door->hit_box.top - 24);
            break;
        default:
            break;
    }
}

void player_move_room(struct_t *store, game_room_t *tmp_ptr
                    , game_room_door_t *door)
{
    char dir = door->direction;

    if (tmp_ptr->lock == 1)
        return;
    if (store->game->map->changing_room == 0)
        move_room_get(store, door, dir);
    store->game->player->hit_box.top = (store->game->player->pos.y + 25);
    store->game->player->hit_box.left = (store->game->player->pos.x + 6);
    sfSprite_setPosition(store->game->player->sprite, store->game->player->pos);
    store->game->map->changing_room = 1;
    store->game->map->changin_room_pos = door->direction;
}