/*
** EPITECH PROJECT, 2021
** menu event
** File description:
** menu_event
*/

#include "rpg.h"

void menu_pars_pages_for(struct_t *store, sfEvent evt, sfKeyCode key)
{
    if (((evt.type == sfEvtKeyPressed && (key == sfKeySpace ||
    key == sfKeyEnter)) || (evt.type == sfEvtMouseButtonPressed &&
    evt.mouseButton.button == sfMouseLeft)) && store->menu->lock == 0) {
        store->menu->lock = 1;
        store->menu->select->rect.left = 12;
    } if (((evt.type == sfEvtKeyReleased && (key == sfKeySpace ||
    key == sfKeyEnter)) || (evt.type == sfEvtMouseButtonReleased &&
    evt.mouseButton.button == sfMouseLeft)) && store->menu->lock == 1) {
        store->menu->lock = 0;
        store->menu->select->rect.left = 0;
        if (store->menu->page == 1) {
            menu_main(store);
        } if (store->menu->page == 0) {
            store->menu->page += 1;
            audio_run_sound(store, SOUND_SELECT);
        }
    }
}

void menu_pars_pages(struct_t *store, sfEvent evt, sfKeyCode key)
{
    menu_pars_pages_for(store, evt, key);
    if (((evt.type == sfEvtKeyPressed && key == sfKeyEscape) ||
    (evt.type == sfEvtMouseButtonPressed &&
    evt.mouseButton.button == sfMouseRight)) && store->menu->lock == 0) {
        store->menu->lock = 1;
    } if (((evt.type == sfEvtKeyReleased && key == sfKeyEscape) ||
    (evt.type == sfEvtMouseButtonReleased &&
    evt.mouseButton.button == sfMouseRight)) && store->menu->lock == 1) {
        if (store->menu->page == 0)
            sfRenderWindow_close(store->win);
        else
            store->menu->page--;
        store->menu->contr->wait_inputs = 0;
        store->menu->lock = 0;
        store->menu->select->rect.left = 0;
        audio_run_sound(store, SOUND_SELECT);
    }
    sfSprite_setTextureRect(store->menu->select->spr
    , store->menu->select->rect);
}

void menu_mouse_selecter(struct_t *store, sfEvent evt)
{
    if (evt.mouseWheelScroll.delta < 0 && store->menu->selected < 3) {
        store->menu->selected++;
        sfSprite_setPosition(store->menu->select->spr,
        store->menu->pos[store->menu->selected]);
        audio_run_sound(store, SOUND_CURSOR);
        store->menu->lock = 0;
        store->menu->select->rect.left = 0;
    } if (evt.mouseWheelScroll.delta > 0.1 && store->menu->selected > 0) {
        store->menu->selected--;
        sfSprite_setPosition(store->menu->select->spr,
        store->menu->pos[store->menu->selected]);
        audio_run_sound(store, SOUND_CURSOR);
        store->menu->lock = 0;
        store->menu->select->rect.left = 0;
    }
}

void menu_selecter(struct_t *store, sfEvent evt, sfKeyCode key)
{
    if ((evt.type == sfEvtKeyPressed && key == sfKeyDown) &&
    store->menu->selected < 3 && store->menu->movelock == 0) {
        store->menu->selected++;
        sfSprite_setPosition(store->menu->select->spr,
        store->menu->pos[store->menu->selected]);
        audio_run_sound(store, SOUND_CURSOR);
        store->menu->movelock = 1;
        store->menu->lock = 0;
        store->menu->select->rect.left = 0;
    } if ((evt.type == sfEvtKeyPressed && key == sfKeyUp) &&
    store->menu->selected > 0 && store->menu->movelock == 0) {
        store->menu->selected--;
        sfSprite_setPosition(store->menu->select->spr,
        store->menu->pos[store->menu->selected]);
        audio_run_sound(store, SOUND_CURSOR);
        store->menu->movelock = 1;
        store->menu->lock = 0;
        store->menu->select->rect.left = 0;
    } if (evt.type == sfEvtKeyReleased && (key == sfKeyDown ||
    key == sfKeyUp) && store->menu->movelock == 1)
        store->menu->movelock = 0;
    menu_mouse_selecter(store, evt);
}

void menu_event(struct_t *store)
{
    while (sfRenderWindow_pollEvent(store->win, &store->evt)) {
        if (store->evt.type == sfEvtClosed)
            sfRenderWindow_close(store->win);
        menu_opt_lock(store);
        if (store->evt.type == sfEvtKeyReleased ||
        store->evt.type == sfEvtMouseWheelScrolled ||
        store->evt.type == sfEvtKeyPressed ||
        store->evt.type == sfEvtMouseButtonPressed ||
        store->evt.type == sfEvtMouseButtonReleased) {
            if (store->menu->page == 1)
                menu_selecter(store, store->evt, store->evt.key.code);
            if (store->menu->page == 3)
                menu_contr_selecter(store, store->evt);
            if (store->menu->page == 2)
                menu_opt_pars_pages(store, store->evt, store->menu->opt);
            menu_pars_pages(store, store->evt, store->evt.key.code);
        }
    }
}