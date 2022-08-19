/*
** EPITECH PROJECT, 2021
** display game
** File description:
** file 1
*/

#include "rpg.h"

static void display_obj_and_door(struct_t *store, game_room_t *tmp
                            , object_t *tmp2, game_room_door_t *tmp3)
{
    int mob = 0;

    for (int subnb = 0; subnb < tmp->nb_object; subnb += 1) {
        if (tmp2->id == OBJ_MOB1 || tmp2->id == OBJ_MOB2
        || tmp2->id == OBJ_MOB3) {
            mob = 1;
            mob_move_all(store, tmp2);
        }
        sfRenderWindow_drawSprite(store->win, tmp2->obj->spr, NULL);
        tmp2 = tmp2->next;
    }
    if (tmp->seed == 50 && store->game->map->changing_basement == 0
        && store->game->map->level != 3 && mob == 0)
            change_basement_anim(store);
    door_handler(tmp, tmp3, mob);
    for (int subnb = 0; subnb < tmp->nb_door; subnb += 1) {
        sfRenderWindow_drawSprite(store->win, tmp3->back->spr, NULL);
        sfRenderWindow_drawSprite(store->win, tmp3->plain->spr, NULL);
        tmp3 = tmp3->next;
    }
}

static void display_player(struct_t *store, arrows_t *tmp4)
{
    if (store->game->player->player_bomb != NULL) {
        sfRenderWindow_drawSprite(store->win
        , store->game->player->player_bomb->bomb->spr, NULL);
        if (store->game->clock->master_time.microseconds
            >= store->game->player->player_bomb->countdown.microseconds)
            bomb_explode(store, store->game->player);

    }
    if (store->game->particles->first_smoke != NULL)
            display_smoke(store);
    for (int nb = 0; nb < store->game->player->nb_arrows; nb += 1) {
        sfRenderWindow_drawSprite(store->win, tmp4->arrow->spr, NULL);
        tmp4 = tmp4->next;
    }
    sfRenderWindow_drawSprite(store->win, store->game->player->sprite, NULL);
}

void display_game(struct_t *store)
{
    game_room_t *tmp = store->game->map->first_room;
    object_t *tmp2 = store->game->map->first_room->first_object;
    game_room_door_t *tmp3 = store->game->map->first_room->first_door;
    arrows_t *tmp4 = store->game->player->player_arrows;

    for (int nb = 0; nb < store->game->map->nb_room; nb += 1) {
        sfRenderWindow_drawSprite(store->win, tmp->back->spr, NULL);
        if (tmp->hide == 1) {
            display_obj_and_door(store, tmp, tmp2, tmp3);
        }
        tmp = tmp->next;
        if (nb < (store->game->map->nb_room - 1)) {
            tmp2 = tmp->first_object;
            tmp3 = tmp->first_door;
        }
    }
    display_player(store, tmp4);
}

void display_game_hud(struct_t *store)
{
    sfRenderWindow_setView(store->win, store->hud);
    sfRenderWindow_drawSprite(store->win
    , store->game->game_text->back[0]->spr, NULL);
    sfRenderWindow_drawSprite(store->win
    , store->game->game_text->back[1]->spr, NULL);
    sfRenderWindow_drawSprite(store->win
    , store->game->game_text->back[2]->spr, NULL);
    for (int nb = 0; nb < 3; nb += 1) {
        sfRenderWindow_drawText(store->win
        , store->game->game_text->text[nb], NULL);
    }
    for (int nb = 0; nb < 5; nb += 1) {
        sfRenderWindow_drawText(store->win
        , store->game->game_text->stats[nb], NULL);
    }
    display_health(store, store->game->game_text);
}