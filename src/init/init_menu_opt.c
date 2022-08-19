/*
** EPITECH PROJECT, 2021
** init menu opt
** File description:
** file 2
*/

#include "rpg.h"

static void init_inputs_text(struct_t *store)
{
    int y = 235;

    for (int nb = 0; nb < 10; nb += 1, y += 85) {
        store->menu->contr->key[nb] = sfText_create();
        sfText_setFont(store->menu->contr->key[nb], store->menu->contr->font);
        store->menu->contr->text[0] = store->settings->inputs[nb] + 'A';
        sfText_setString(store->menu->contr->key[nb],
        store->menu->contr->text);
        sfText_scale(store->menu->contr->key[nb], (sfVector2f) {2, 2});
        sfText_setPosition(store->menu->contr->key[nb],
        (sfVector2f) {1450, y});
        sfText_setColor(store->menu->contr->key[nb], sfBlack);
    }
}

void init_menu_cont(struct_t *store)
{
    store->menu->contr->selected = 0;
    store->menu->contr->lock = 0;
    store->menu->contr->movelock = 0;
    store->menu->contr->controls = create_elem("src/files/opt/controls.png",
    vec(0, 0), rect(0, 0, 480, 270), 4);
    store->menu->contr->select = create_elem("src/files/menu/select.png",
    store->menu->contr->pos[0], rect(0, 0, 12, 15), 4);
    store->menu->contr->wait_inputs = 0;
    store->menu->contr->text[1] = '\0';
    store->menu->contr->font =
    sfFont_createFromFile("src/files/game/gamefont.ttf");
    init_inputs_text(store);
}