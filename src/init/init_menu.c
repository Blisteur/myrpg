/*
** EPITECH PROJECT, 2021
** init_menu
** File description:
** init_menu
*/

#include "rpg.h"

void init_menu_opt(struct_t *store)
{
    store->menu->opt->selected = 0;
    store->menu->opt->lock = 0;
    store->menu->opt->movelock = 0;
    store->menu->opt->options = create_elem("src/files/opt/options.png",
    vec(0, 0), rect(0, 0, 480, 270), 4);
    store->menu->opt->res = create_elem("src/files/opt/res.png",
    vec(860, 780), rect(store->menu->opt->isres, 0, 70, 25), 4);
    store->menu->opt->mus_bar = create_elem("src/files/opt/mus_bar.png",
    vec(1080, 448), rect(0, 0, store->menu->opt->ismusic, 16), 4);
    store->menu->opt->sfx_bar = create_elem("src/files/opt/sfx_bar.png",
    vec(1072, 364), rect(0, 0, store->menu->opt->issfx, 16), 4);
    store->menu->opt->full_on = create_elem("src/files/opt/full_on.png",
    vec(1180, 552), rect(0, 0, store->menu->opt->isfull * 36, 18), 4);
    store->menu->opt->select = create_elem("src/files/menu/select.png",
    store->menu->opt->pos[0], rect(0, 0, 12, 15), 4);
    store->menu->opt->tuto = create_elem("src/files/opt/tuto.png",
    vec(1300, 780), rect(0, 0, 372, 264), 1);
}

void init_menu_main(struct_t *store)
{
    store->menu->page = 0;
    store->menu->selected = 0;
    store->menu->lock = 0;
    store->menu->movelock = 0;
    store->menu->main = create_elem("src/files/menu/main.png", vec(0, 0),
    rect(0, 0, 480, 270), 4);
    store->menu->logo = create_elem("src/files/menu/logo.png", vec(360, 200),
    rect(0, 0, 1200, 489), 1);
    store->menu->menu = create_elem("src/files/menu/menu.png", vec(0, 0),
    rect(0, 0, 480, 270), 4);
    store->menu->cont = create_elem("src/files/menu/cont.png", vec(0, 0),
    rect(0, 0, 103, 31), 4);
    store->menu->select = create_elem("src/files/menu/select.png",
    store->menu->pos[0], rect(0, 0, 12, 15), 4);
    init_menu_opt(store);
    init_menu_cont(store);
}

void init_settings_values(struct_t *store)
{
    store->menu->opt->isfull = store->settings->fullscreen;
    store->menu->opt->isres = 0;
    store->menu->opt->istuto = 0;
    if (store->settings->resolution[1] == 1080)
        store->menu->opt->isres = 0;
    if (store->settings->resolution[1] == 720)
        store->menu->opt->isres = 70;
    if (store->settings->resolution[1] == 600)
        store->menu->opt->isres = 140;
    store->menu->opt->issfx = ((store->settings->volume[1] / 10) * 6);
    store->menu->opt->ismusic = ((store->settings->volume[0] / 10) * 6);
}

void init_menu(struct_t *store)
{
    sfVector2f menu_pos[4] = {{660, 270}, {672, 388}, {700, 530}, {780, 655}};
    sfVector2f opt_pos[6] = {{650, 264}, {635, 375}, {630, 470}, {635, 570},
    {670, 690}, {670, 925}};
    sfVector2f cont_pos[10] = {{290, 235}, {290, 320}, {290, 405}, {290, 485},
    {290, 570}, {290, 650}, {290, 740}, {290, 820}, {290, 905}, {290, 995}};

    store->menu = malloc(sizeof(menu_t));
    store->menu->opt = malloc(sizeof(option_t));
    store->menu->contr = malloc(sizeof(controls_t));
    for (int i = 0; i != 10; i++) {
        if (i < 4)
            store->menu->pos[i] = menu_pos[i];
        if (i < 6)
            store->menu->opt->pos[i] = opt_pos[i];
        store->menu->contr->pos[i] = cont_pos[i];
    }
    init_settings_values(store);
    init_menu_main(store);
    menu_audio(store, 1);
}