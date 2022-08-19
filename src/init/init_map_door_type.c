/*
** EPITECH PROJECT, 2021
** init_map_type
** File description:
** file 1
*/

#include "rpg.h"

void init_up_door(game_room_door_t *p, sfVector2f pos)
{
    p->back = create_elem("src/files/game/doors.png", pos,
    rect(0, 0, 49, 33), 4);
    p->plain = create_elem("src/files/game/doors.png", pos,
    rect(49, 0, 49, 33), 4);
    p->direction = 'u';
    p->hit_box = (sfFloatRect) {pos.x + 49 + 5, pos.y, 98 - 10, 132 - 12};
}

void init_down_door(game_room_door_t *p, sfVector2f pos)
{
    p->back = create_elem("src/files/game/doors.png", pos,
    rect(0, 0, 49, 33), 1);
    p->plain = create_elem("src/files/game/doors.png", pos,
    rect(49, 0, 49, 33), 1);
    sfSprite_scale(p->back->spr, (sfVector2f) {4, -4});
    sfSprite_scale(p->plain->spr, (sfVector2f) {4, -4});
    p->direction = 'd';
    p->hit_box = (sfFloatRect) {pos.x + 49 + 5, pos.y - 132 + 12, 98 - 10,
    132 - 12};
}

void init_left_door(game_room_door_t *p, sfVector2f pos)
{
    p->back = create_elem("src/files/game/doors.png", pos,
    rect(0, 0, 49, 33), 4);
    p->plain = create_elem("src/files/game/doors.png", pos,
    rect(49, 0, 49, 33), 4);
    sfSprite_rotate(p->back->spr, -90);
    sfSprite_rotate(p->plain->spr, -90);
    p->direction = 'l';
    p->hit_box = (sfFloatRect) {pos.x - 8, pos.y - 132, 132, 98 - 20};
}

void init_right_door(game_room_door_t *p, sfVector2f pos)
{
    p->back = create_elem("src/files/game/doors.png", pos,
    rect(0, 0, 49, 33), 4);
    p->plain = create_elem("src/files/game/doors.png", pos,
    rect(49, 0, 49, 33), 4);
    sfSprite_rotate(p->back->spr, 90);
    sfSprite_rotate(p->plain->spr, 90);
    p->direction = 'r';
    p->hit_box = (sfFloatRect) {pos.x - 132 + 8, pos.y + 33 + 20, 132,
    98 - 10};
}