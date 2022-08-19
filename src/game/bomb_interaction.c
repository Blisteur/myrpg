/*
** EPITECH PROJECT, 2021
** bomb_interaction
** File description:
** bomb_interaction
*/

#include "rpg.h"

void change_obj_fire(object_t *obj)
{
    obj->obj->rect.top = 60;
    obj->hit_box.left = 0;
    obj->hit_box.top = 0;
    obj->hit_box.width = 0;
    obj->hit_box.height = 0;
}

void change_obj_exploded(object_t *obj)
{
    obj->obj->rect.left = 81;
    sfSprite_setTextureRect(obj->obj->spr, obj->obj->rect);
    obj->hit_box.left = 0;
    obj->hit_box.top = 0;
    obj->hit_box.width = 0;
    obj->hit_box.height = 0;
    return;
}

void damage_player(struct_t *store, player_t *player, int amount)
{
    float cur = sfTime_asMilliseconds(store->game->clock->master_time);

    if (cur > player->stats->grace) {
        amount -= player->stats->def;
        if (amount < 1)
            amount = 1;
        player->stats->cur_hp -= amount;
        player->stats->grace = cur + 1000;
    }
    return;
}

static void destroy_rocks_parser(object_t *temp,
sfVector2f obj_pos, sfVector2f bomb)
{
    if (temp->id == OBJ_ROCK) {
        if (in_range(bomb, 256, obj_pos) == 1)
            change_obj_exploded(temp);
    }
    if (temp->id == OBJ_FIRE) {
        if (in_range(bomb, 256, obj_pos) == 1)
            change_obj_fire(temp);
    }
}

void destroy_rocks(struct_t *store, player_t *player)
{
    object_t *temp;
    game_room_t *temp_room = store->game->map->first_room;
    sfVector2f bomb = {player->player_bomb->pos.x, player->player_bomb->pos.y};
    sfVector2f obj_pos;

    for (; temp_room->id != player->room_id; temp_room = temp_room->next);
    temp = temp_room->first_object;
    for (int nb = 0; nb < temp_room->nb_object; nb += 1) {
        obj_pos.x = temp->obj->pos.x + (temp->hit_box.width / 2);
        obj_pos.y = temp->obj->pos.y + (temp->hit_box.height / 2);
        destroy_rocks_parser(temp, obj_pos, bomb);
        if (temp->id == OBJ_MOB1 || temp->id == OBJ_MOB2 ||
        temp->id == OBJ_MOB3 || temp->id == OBJ_MOB4) {
            hurt_mob(store, temp_room, temp);
            return;
        }
        temp = temp->next;
    }
    return;
}