/*
** EPITECH PROJECT, 2021
** obj_move
** File description:
** file 1
*/

#include "rpg.h"

int arrow_hitbox(struct_t *store, sfFloatRect tmp)
{
    game_room_t *tmp_ptr = store->game->map->first_room;
    object_t *tmp2_ptr = store->game->map->first_room->first_object;
    int cur = store->game->player->room_id;

    for (int nb = 0; nb < store->game->map->nb_room; nb += 1) {

        for (int subnb = 0; tmp_ptr->id == cur
            && subnb < tmp_ptr->nb_object; subnb += 1) {
            if (sfFloatRect_intersects(&tmp, &tmp2_ptr->hit_box,
            NULL) == sfTrue)
                return (arrow_get_obj(store, tmp_ptr, tmp2_ptr));
            tmp2_ptr = tmp2_ptr->next;
        }
        tmp_ptr = tmp_ptr->next;
        if (nb < (store->game->map->nb_room - 1))
            tmp2_ptr = tmp_ptr->first_object;
    }
    return (0);
}

int check_range(struct_t *store, arrows_t *arrow)
{
    float max = (store->game->player->stats->range * 500);
    float dx = arrow->origin.x - arrow->hit_box.left;
    float dy = arrow->origin.y - arrow->hit_box.top;

    if (dx > max || dx < (max * -1) || dy > max || dy < (max * -1))
        return (1);
    return (0);
}

void set_arrow_pos(arrows_t *arrow, float dx, float dy)
{
    arrow->hit_box.left += dx;
    arrow->arrow->pos.x += dx;
    arrow->hit_box.top += dy;
    arrow->arrow->pos.y += dy;
    sfSprite_setPosition(arrow->arrow->spr, arrow->arrow->pos);
}

void arrow_move(struct_t *store, arrows_t *arrows, int dir)
{
    float dx = get_distance(store, store->game->player->stats->atk_spd * 5);
    float dy = get_distance(store, store->game->player->stats->atk_spd * 5);

    switch (dir) {
        case 1:
            set_arrow_pos(arrows, 0, (dy * -1));
            break;
        case 2:
            set_arrow_pos(arrows, 0, dy);
            break;
        case 3:
            set_arrow_pos(arrows, (dx * -1), 0);
            break;
        case 4:
            set_arrow_pos(arrows, dx, 0);
            break;
        default:
            break;
    }
}

void obj_move(struct_t *store)
{
    arrows_t *arrows;

    if (store->game->player->nb_arrows == 0 ||
    store->game->player->player_arrows == NULL)
        return;
    arrows = store->game->player->player_arrows;
    for (int a = store->game->player->nb_arrows; a > 0; a--) {
        if (arrows->direct >= 0) {
            if (check_range(store, arrows) == 1 ||
            arrow_hitbox(store, arrows->hit_box) == 1) {
                set_arrow_pos(arrows, -16000, -16000);
                arrows->direct = -1;
            }
            arrow_move(store, arrows, arrows->direct);
        }
        arrows = arrows->next;
    }
}