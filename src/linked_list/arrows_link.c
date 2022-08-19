/*
** EPITECH PROJECT, 2021
** link arrows
** File description:
** file
*/

#include "rpg.h"

arrows_t *add_arrows(struct_t *store, arrows_t *p, sfVector2f pos)
{
    arrows_t *list = malloc(sizeof(arrows_t));

    list->next = p;
    p = list;
    p->arrow = create_elem("src/files/game/arrow.png",
    pos, rect(0, 0, 16, 5), 4);
    p->hit_box = (sfFloatRect) {pos.x, pos.y, 10, 10};
    p->origin = (sfVector2f) {pos.x, pos.y};
    p->direct = store->game->player->player_atk_type;
    if (p->direct == 1) {
        sfSprite_rotate(p->arrow->spr, -90);
    }
    if (p->direct == 2) {
        sfSprite_rotate(p->arrow->spr, 90);
    }
    if (p->direct == 3) {
        sfSprite_rotate(p->arrow->spr, 180);
    }
    store->game->player->nb_arrows += 1;
    return (list);
}

void remove_arrows(player_t *player, arrows_t *p)
{
    if (p == player->player_arrows)
        player->player_arrows = p->next;
    player->nb_arrows -= 1;
    destroy_elem(p->arrow);
    free(p);
}

void remove_all_arrows(player_t *player)
{
    while (player->nb_arrows != 0)
        remove_arrows(player, player->player_arrows);
}