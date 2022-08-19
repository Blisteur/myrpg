/*
** EPITECH PROJECT, 2021
** player move
** File description:
** file 1
*/

#include "rpg.h"

static int get_hitbox_wall(sfFloatRect tmp, game_room_t *tmp_ptr)
{
    for (int subnb = 0; subnb < 4; subnb += 1) {
        if (sfFloatRect_intersects(&tmp, &tmp_ptr->hit_box_wall[subnb],
        NULL) == sfTrue)
            return (1);
    }
    return (0);
}

static int get_hitbox_obj(struct_t *store, sfFloatRect tmp
                        , game_room_t *tmp_ptr, object_t *tmp2_ptr)
{
    for (int subnb = 0; subnb < tmp_ptr->nb_object; subnb += 1) {
        if (sfFloatRect_intersects(&tmp, &tmp2_ptr->hit_box,
        NULL) == sfTrue)
            return (player_get_obj(store, tmp_ptr, tmp2_ptr));
        if (store->game->debug == 1 && tmp_ptr->id ==
        store->game->player->room_id)
            show_hitbox(store, tmp2_ptr->hit_box);
        tmp2_ptr = tmp2_ptr->next;
    }
    return (0);
}

static void get_hitbox_door(struct_t *store, sfFloatRect tmp
                        , game_room_t *tmp_ptr, game_room_door_t *tmp3_ptr)
{
    for (int subnb = 0; subnb < tmp_ptr->nb_door; subnb += 1) {
        if (sfFloatRect_intersects(&tmp, &tmp3_ptr->hit_box,
        NULL) == sfTrue)
            player_move_room(store, tmp_ptr, tmp3_ptr);
        tmp3_ptr = tmp3_ptr->next;
    }
}

int get_hitbox(struct_t *store, sfFloatRect tmp)
{
    game_room_t *tmp_ptr = store->game->map->first_room;
    object_t *tmp2_ptr = store->game->map->first_room->first_object;
    game_room_door_t *tmp3_ptr = store->game->map->first_room->first_door;

    if (store->game->debug == 1)
        show_hitbox(store, tmp);
    for (int nb = 0; nb < store->game->map->nb_room; nb += 1) {
        if (get_hitbox_wall(tmp, tmp_ptr) == 1)
            return (1);
        if (get_hitbox_obj(store, tmp, tmp_ptr, tmp2_ptr) == 1)
            return (1);
        get_hitbox_door(store, tmp, tmp_ptr, tmp3_ptr);
        tmp_ptr = tmp_ptr->next;
        if (nb < (store->game->map->nb_room - 1)) {
            tmp2_ptr = tmp_ptr->first_object;
            tmp3_ptr = tmp_ptr->first_door;
        }
    }
    return (0);
}

void player_move(struct_t *store, player_t *player)
{
    if (player->pos.y != 0)
        player->speedy *= 0.85;
    if (player->pos.x != 0)
        player->speedx *= 0.85;
    get_player_next_pos(store, player, 0);
    sfSprite_setPosition(player->sprite, player->pos);
    player->hit_box.top = player->pos.y;
    player->hit_box.left = player->pos.x;
}