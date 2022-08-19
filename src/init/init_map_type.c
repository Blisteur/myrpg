/*
** EPITECH PROJECT, 2021
** init_map_type
** File description:
** file 1
*/

#include "rpg.h"

void init_spawn_room(game_room_t *p, sfVector2f pos)
{
    p->seed = 1;
    p->back = create_elem("src/files/game/basement.png"
    , pos, rect(0, 0, 480, 270), 4);
    p->hide = 1;
    p->lock = 0;
    p->hit_box_wall[0] = (sfFloatRect) {pos.x, pos.y, 1920, 200};
    p->hit_box_wall[1]
    = (sfFloatRect) {pos.x, (pos.y + 1080 - 200), 1920, 200};
    p->hit_box_wall[2] = (sfFloatRect) {pos.x, pos.y, 204, 1080};
    p->hit_box_wall[3]
    = (sfFloatRect) {(pos.x + 1920 - 204), pos.y, 204, 1080};
    p->player_here = (sfFloatRect) {pos.x, pos.y, 1920, 1080};
}

void init_basic_room(game_room_t *p, sfVector2f pos)
{
    p->seed = (rand() % 8) + 2;
    p->back = create_elem("src/files/game/basement.png"
    , pos, rect(0, 0, 480, 270), 4);
    p->hide = 0;
    p->lock = 1;
    p->hit_box_wall[0] = (sfFloatRect) {pos.x, pos.y, 1920, 200};
    p->hit_box_wall[1]
    = (sfFloatRect) {pos.x, (pos.y + 1080 - 200), 1920, 200};
    p->hit_box_wall[2] = (sfFloatRect) {pos.x, pos.y, 204, 1080};
    p->hit_box_wall[3]
    = (sfFloatRect) {(pos.x + 1920 - 204), pos.y, 204, 1080};
    p->player_here = (sfFloatRect) {pos.x, pos.y, 1920, 1080};
}

void init_special_room(game_room_t *p, sfVector2f pos)
{
    p->seed = 67;
    p->back = create_elem("src/files/game/basement.png"
    , pos, rect(0, 0, 480, 270), 4);
    p->hide = 0;
    p->lock = 0;
    p->hit_box_wall[0] = (sfFloatRect) {pos.x, pos.y, 1920, 200};
    p->hit_box_wall[1]
    = (sfFloatRect) {pos.x, (pos.y + 1080 - 200), 1920, 200};
    p->hit_box_wall[2] = (sfFloatRect) {pos.x, pos.y, 204, 1080};
    p->hit_box_wall[3]
    = (sfFloatRect) {(pos.x + 1920 - 204), pos.y, 204, 1080};
    p->player_here = (sfFloatRect) {pos.x, pos.y, 1920, 1080};
}

void init_item_room(game_room_t *p, sfVector2f pos)
{
    p->seed = 57;
    p->back = create_elem("src/files/game/basement.png"
    , pos, rect(0, 0, 480, 270), 4);
    p->hide = 0;
    p->lock = 0;
    p->hit_box_wall[0] = (sfFloatRect) {pos.x, pos.y, 1920, 200};
    p->hit_box_wall[1]
    = (sfFloatRect) {pos.x, (pos.y + 1080 - 200), 1920, 200};
    p->hit_box_wall[2] = (sfFloatRect) {pos.x, pos.y, 204, 1080};
    p->hit_box_wall[3]
    = (sfFloatRect) {(pos.x + 1920 - 204), pos.y, 204, 1080};
    p->player_here = (sfFloatRect) {pos.x, pos.y, 1920, 1080};
}