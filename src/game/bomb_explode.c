/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** bomb_explode.c
*/

#include "rpg.h"

int in_range(sfVector2f center, int radius, sfVector2f target)
{
    int x;
    int y;
    int rad;

    x = (target.x - center.x);
    x = x * x;
    y = (target.y - center.y);
    y = y * y;
    rad = radius * radius;
    if (x + y <= rad)
        return (1);
    return (0);
}

void create_smoke(struct_t *store, sfVector2f pos)
{
    if (store->game->particles->first_smoke == NULL) {
        store->game->particles->first_smoke = malloc(sizeof(particles_t));
        store->game->particles->first_smoke->next = NULL;
        store->game->particles->first_smoke->p =
        create_elem("src/files/game/smoke.png", pos, rect(0, 0, 23, 23), 1);
    } else {
        particles_t *new_elem = malloc(sizeof(particles_t));
        new_elem->p = create_elem("src/files/game/smoke.png",
        pos, rect(0, 0, 23, 23), 1);
        new_elem->next = store->game->particles->first_smoke;
        store->game->particles->first_smoke = new_elem;
    }
}

void destroy_smoke(struct_t *store)
{
    particles_t *to_free = store->game->particles->first_smoke;

    store->game->particles->time_smoke.microseconds
    += store->game->clock->delta_time.microseconds;
    if (store->game->particles->time_smoke.microseconds > 3000000) {
        while (store->game->particles->first_smoke != NULL) {
            to_free = store->game->particles->first_smoke;
            store->game->particles->first_smoke
            = store->game->particles->first_smoke->next;
            destroy_elem(to_free->p);
            free(to_free);
        }
    }
}

void display_smoke(struct_t *store)
{
    for (particles_t *boat = store->game->particles->first_smoke;
    boat != NULL; boat = boat->next) {
        sfRenderWindow_drawSprite(store->win, boat->p->spr, NULL);
    }
    destroy_smoke(store);
}

void bomb_explode(struct_t *store, player_t *player)
{
    sfVector2f bomb = {player->player_bomb->pos.x, player->player_bomb->pos.y};
    sfVector2f pos = {player->hit_box.left + (player->hit_box.width / 2),
                    player->hit_box.top + (player->hit_box.height / 2)};
    sfVector2f smoke_pos = {0, 0};

    if (in_range(bomb, 256, pos) == 1)
        damage_player(store, player, 1);
    destroy_rocks(store, player);
    for (int i = 0; i < 10; i++) {
        smoke_pos.x = (float) ((rand() % 101) +
        (player->player_bomb->pos.x - 20));
        smoke_pos.y = (float) ((rand() % 101) +
        (player->player_bomb->pos.y - 20));
        create_smoke(store, smoke_pos);
    }
    destroy_elem(player->player_bomb->bomb);
    free(player->player_bomb);
    player->player_bomb = NULL;
    store->game->particles->time_smoke.microseconds = 0;
}