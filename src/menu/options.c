/*
** EPITECH PROJECT, 2021
** menu options
** File description:
** options
*/

#include "rpg.h"

void menu_opt_lock(struct_t *store)
{
    if (store->evt.type == sfEvtMouseButtonPressed &&
    store->evt.mouseButton.button == sfMouseLeft && store->menu->page == 2) {
        my_printf("lock: %d\n", store->menu->opt->lock);
        if (store->menu->opt->lock == 0)
            store->menu->opt->lock = 1;
        else if (store->menu->opt->lock == 1)
            store->menu->opt->lock = 0;
    }
}

void menu_opt_pars(struct_t *store)
{
    if (store->menu->opt->selected == 1)
        menu_opt_sound(store, store->evt);
    if (store->menu->opt->selected == 2)
        menu_opt_music(store, store->evt);
    if (store->menu->opt->selected == 3)
        menu_opt_fullscreen(store, store->evt, store->menu->opt);
    if (store->menu->opt->selected == 4)
        menu_opt_res(store, store->evt, store->menu->opt);
    if (store->menu->opt->selected == 5)
        store->menu->opt->istuto = 1;
    else
        store->menu->opt->istuto = 0;
}

void menu_opt_mouse_selecter(struct_t *store, sfEvent evt, option_t *opt)
{
    if (evt.mouseWheelScroll.delta < 0 && opt->selected < 5) {
        opt->selected++;
        sfSprite_setPosition(opt->select->spr, opt->pos[opt->selected]);
        audio_run_sound(store, SOUND_CURSOR);
    } if (evt.mouseWheelScroll.delta > 0.1 && opt->selected > 0) {
        opt->selected--;
        sfSprite_setPosition(opt->select->spr, opt->pos[opt->selected]);
        audio_run_sound(store, SOUND_CURSOR);
    }
}

void menu_opt_selecter(struct_t *store, sfEvent evt, sfKeyCode key,
                    option_t *opt)
{
    if ((evt.type == sfEvtKeyPressed && key == sfKeyDown) &&
    opt->selected < 5 && opt->movelock == 0) {
        opt->selected++;
        sfSprite_setPosition(opt->select->spr, opt->pos[opt->selected]);
        audio_run_sound(store, SOUND_CURSOR);
        opt->movelock = 1;
        opt->lock = 0;
        opt->select->rect.left = 0;
    } if ((evt.type == sfEvtKeyPressed && key == sfKeyUp) &&
    opt->selected > 0 && opt->movelock == 0) {
        opt->selected--;
        sfSprite_setPosition(opt->select->spr, opt->pos[opt->selected]);
        audio_run_sound(store, SOUND_CURSOR);
        opt->movelock = 1;
        opt->lock = 0;
        opt->select->rect.left = 0;
    } if (evt.type == sfEvtKeyReleased && (key == sfKeyDown ||
    key == sfKeyUp) && opt->movelock == 1)
        opt->movelock = 0;
    menu_opt_mouse_selecter(store, evt, opt);
}

void menu_opt_pars_pages(struct_t *store, sfEvent evt, option_t *opt)
{
    menu_opt_selecter(store, evt, evt.key.code, opt);
    if (((evt.type == sfEvtKeyPressed && (evt.key.code == sfKeySpace ||
    evt.key.code == sfKeyEnter) && opt->lock == 0) ||
    (evt.type == sfEvtMouseButtonPressed &&
    evt.mouseButton.button == sfMouseLeft)) && opt->selected == 0) {
        opt->lock = 1;
        opt->select->rect.left = 12;
    } if (((evt.type == sfEvtKeyReleased && (evt.key.code == sfKeySpace ||
    evt.key.code == sfKeyEnter) && opt->lock == 1) ||
    (evt.type == sfEvtMouseButtonReleased &&
    evt.mouseButton.button == sfMouseLeft)) && opt->selected == 0) {
        opt->lock = 0;
        opt->select->rect.left = 0;
        store->menu->page = 3;
    }
    sfSprite_setTextureRect(opt->select->spr, opt->select->rect);
    menu_opt_pars(store);
}