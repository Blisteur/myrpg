/*
** EPITECH PROJECT, 2021
** controls
** File description:
** controls
*/

#include "rpg.h"

void wait_inputs(struct_t *store)
{
    if (store->menu->contr->wait_inputs == 1 &&
    store->evt.key.code != sfKeyEscape) {
        store->settings->inputs[store->menu->contr->selected] =
        store->evt.key.code;
        store->menu->contr->text[0] = store->evt.key.code + 'A';
        sfText_setString(store->menu->contr->key[store->menu->contr->selected]
        , store->menu->contr->text);
        store->menu->contr->wait_inputs = 0;
        store->settings->is_modified = 1;
        store->menu->contr->select->rect.left = 0;
    }
    if ((store->evt.key.code == sfKeySpace
    || store->evt.key.code == sfKeyEnter) &&
    store->evt.key.type == sfEvtKeyReleased) {
        store->menu->contr->wait_inputs = 1;
        store->menu->contr->select->rect.left = 12;
    }
    sfSprite_setTextureRect(store->menu->contr->select->spr
        , store->menu->contr->select->rect);
}

void menu_contr_mouse_selecter(struct_t *store, sfEvent evt)
{
    if (evt.mouseWheelScroll.delta < 0 && store->menu->contr->selected < 9 &&
    store->menu->contr->wait_inputs == 0) {
        store->menu->contr->selected++;
        sfSprite_setPosition(store->menu->contr->select->spr,
        store->menu->contr->pos[store->menu->contr->selected]);
        audio_run_sound(store, SOUND_CURSOR);
    } if (evt.mouseWheelScroll.delta > 0.1 &&
    store->menu->contr->selected > 0 && store->menu->contr->wait_inputs == 0) {
        store->menu->contr->selected--;
        sfSprite_setPosition(store->menu->contr->select->spr,
        store->menu->contr->pos[store->menu->contr->selected]);
        audio_run_sound(store, SOUND_CURSOR);
    }
}

void menu_contr_selecter(struct_t *store, sfEvent evt)
{
    if (evt.type == sfEvtKeyPressed && evt.key.code == sfKeyDown &&
    store->menu->contr->selected < 9 && store->menu->contr->movelock == 0 &&
    store->menu->contr->wait_inputs == 0) {
        store->menu->contr->movelock = 1;
        store->menu->contr->selected++;
        sfSprite_setPosition(store->menu->contr->select->spr,
        store->menu->contr->pos[store->menu->contr->selected]);
        audio_run_sound(store, SOUND_CURSOR);
    } if (evt.type == sfEvtKeyPressed && evt.key.code == sfKeyUp &&
    store->menu->contr->selected > 0 && store->menu->contr->movelock == 0 &&
    store->menu->contr->wait_inputs == 0) {
        store->menu->contr->movelock = 1;
        store->menu->contr->selected--;
        sfSprite_setPosition(store->menu->contr->select->spr,
        store->menu->contr->pos[store->menu->contr->selected]);
        audio_run_sound(store, SOUND_CURSOR);
    } if (evt.type == sfEvtKeyReleased && store->menu->contr->movelock == 1)
        store->menu->contr->movelock = 0;
    menu_contr_mouse_selecter(store, evt);
    wait_inputs(store);
}