/*
** EPITECH PROJECT, 2021
** init game hud
** File description:
** file 1
*/

#include "rpg.h"

static void init_health(game_text_t *hud)
{
    hud->hpbar = sfSprite_create();
    hud->hp = sfTexture_createFromFile("src/files/game/life.png", NULL);
    hud->rect = (sfIntRect) {0, 0, 7, 7};
    sfSprite_setTexture(hud->hpbar, hud->hp, sfFalse);
    sfSprite_setTextureRect(hud->hpbar, hud->rect);
    sfSprite_setScale(hud->hpbar, (sfVector2f){6, 6});
}

static void init_stats(struct_t *store)
{
    sfVector2f pos = {50, 400};
    int pos_y = 200;

    for (int nb = 0; nb < 5; nb += 1) {
        store->game->game_text->stats[nb] = sfText_create();
        sfText_setFont(store->game->game_text->stats[nb]
        , store->game->game_text->font);
        sfText_setString(store->game->game_text->stats[nb], "0");
        sfText_setPosition(store->game->game_text->stats[nb], pos);
        pos.y += 50;
    }
    for (int nb = 0; nb < 3; nb += 1) {
        store->game->game_text->text[nb] = sfText_create();
        sfText_setFont(store->game->game_text->text[nb]
        , store->game->game_text->font);
        sfText_setString(store->game->game_text->text[nb], "000");
        sfText_setPosition(store->game->game_text->text[nb]
        , (sfVector2f) {1850, pos_y});
        pos_y += 50;
    }
}

static void init_text_hud(struct_t *store)
{
    update_txt_inv(store->game->player->bomb, store->game->game_text->text[0]);
    update_txt_inv(store->game->player->key, store->game->game_text->text[1]);
    update_txt_inv(store->game->player->money, store->game->game_text->text[2]);
    update_txt_stats((int) (store->game->player->stats->atk)
    , store->game->game_text->stats[0], "ATK");
    update_txt_stats((int) (store->game->player->stats->atk_spd)
    , store->game->game_text->stats[1], "ATS");
    update_txt_stats((int) (store->game->player->stats->range)
    , store->game->game_text->stats[2], "RNG");
    update_txt_stats((int) (store->game->player->stats->speed)
    , store->game->game_text->stats[3], "SPD");
    update_txt_stats(store->game->player->stats->def
    , store->game->game_text->stats[4], "DEF");
}

void init_hud(struct_t *store)
{
    store->game->game_text = malloc(sizeof(game_text_t));
    store->game->game_text->font
    = sfFont_createFromFile("src/files/game/gamefont.ttf");
    store->game->game_text->back[0] = create_elem("src/files/game/items.png"
    , vec(1800, 200), rect(0, 0, 20, 20), 2);
    store->game->game_text->back[1] = create_elem("src/files/game/items.png"
    , vec(1800, 250), rect(20, 0, 20, 20), 2);
    store->game->game_text->back[2] = create_elem("src/files/game/items.png"
    , vec(1800, 300), rect(40, 0, 20, 20), 2);
    init_health(store->game->game_text);
    init_stats(store);
    init_text_hud(store);
}

void destroy_hud(struct_t *store)
{
    for (int nb = 0; nb < 3; nb += 1) {
        sfText_destroy(store->game->game_text->text[nb]);
    }
    for (int nb = 0; nb < 5; nb += 1) {
        sfText_destroy(store->game->game_text->stats[nb]);
    }
    destroy_elem(store->game->game_text->back[0]);
    destroy_elem(store->game->game_text->back[1]);
    destroy_elem(store->game->game_text->back[2]);
    sfFont_destroy(store->game->game_text->font);
    sfSprite_destroy(store->game->game_text->hpbar);
    sfTexture_destroy(store->game->game_text->hp);
    free(store->game->game_text);
}