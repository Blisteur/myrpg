/*
** EPITECH PROJECT, 2021
** menu options modifiers
** File description:
** menu_opt_modifiers
*/

#include "rpg.h"

void menu_opt_sound_mod(struct_t *store, int type, int mod)
{
    if (type == 0) {
        store->menu->opt->issfx += (mod * 6);
        change_sound_vl(store, mod);
        audio_run_sound(store, SOUND_CURSOR);
    } else {
        store->menu->opt->ismusic += (mod * 6);
        change_master_vl(store, mod);
        audio_run_sound(store, SOUND_CURSOR);
    }
}

void menu_opt_music(struct_t *store, sfEvent evt)
{
    if ((evt.type == sfEvtKeyPressed && evt.key.code == sfKeyRight) &&
    store->menu->opt->ismusic < 60 && store->menu->opt->movelock == 0) {
        menu_opt_sound_mod(store, 1, 1);
        store->menu->opt->movelock = 1;
    } if ((evt.type == sfEvtKeyPressed && evt.key.code == sfKeyLeft) &&
    store->menu->opt->ismusic > 0) {
        menu_opt_sound_mod(store, 1, -1);
    } if (evt.type == sfEvtKeyReleased && (evt.key.code == sfKeyRight ||
    evt.key.code == sfKeyLeft) && store->menu->opt->movelock == 1)
        store->menu->opt->movelock = 0;
    sfSprite_setTextureRect(store->menu->opt->mus_bar->spr,
    rect(0, 0, store->menu->opt->ismusic, 16));
}

void menu_opt_sound(struct_t *store, sfEvent evt)
{
    if ((evt.type == sfEvtKeyPressed && evt.key.code == sfKeyRight) &&
    store->menu->opt->issfx < 60 && store->menu->opt->movelock == 0) {
        menu_opt_sound_mod(store, 0, 1);
        store->menu->opt->movelock = 1;
    } if ((evt.type == sfEvtKeyPressed && evt.key.code == sfKeyLeft) &&
    store->menu->opt->issfx > 0 && store->menu->opt->movelock == 0) {
        menu_opt_sound_mod(store, 0, -1);
        store->menu->opt->movelock = 1;
    } if (evt.type == sfEvtKeyReleased && (evt.key.code == sfKeyRight ||
    evt.key.code == sfKeyLeft) && store->menu->opt->movelock == 1)
        store->menu->opt->movelock = 0;
    sfSprite_setTextureRect(store->menu->opt->sfx_bar->spr,
    rect(0, 0, store->menu->opt->issfx, 16));
}

void menu_opt_res(struct_t *store, sfEvent evt, option_t *opt)
{
    int comp = opt->isres;

    if (evt.type == sfEvtKeyPressed && opt->movelock == 0) {
        if (evt.key.code == sfKeyRight)
            opt->isres += 70;
        if (evt.key.code == sfKeyLeft)
            opt->isres -= 70;
        opt->movelock = 1;
    } if (evt.type == sfEvtKeyReleased && (evt.key.code == sfKeyRight ||
    evt.key.code == sfKeyLeft) && opt->movelock == 1)
        opt->movelock = 0;
    if (opt->isres == -70)
        opt->isres = 140;
    if (opt->isres == 210)
        opt->isres = 0;
    if (comp != opt->isres) {
        change_resolution(store, (opt->isres / 70));
        sfSprite_setTextureRect(opt->res->spr, rect(opt->isres, 0, 70, 25));
    }
}

void menu_opt_fullscreen(struct_t *store, sfEvent evt, option_t *opt)
{
    if ((evt.type == sfEvtKeyPressed && (evt.key.code == sfKeyRight ||
    evt.key.code == sfKeyLeft))
    && opt->movelock == 0) {
        opt->movelock = 1;
        if (opt->isfull == 0) {
            opt->isfull = 1;
            sfSprite_setTextureRect(opt->full_on->spr, rect(0, 0, 36, 18));
            change_fullscreen(store);
        } else {
            opt->isfull = 0;
            sfSprite_setTextureRect(opt->full_on->spr, rect(0, 0, 0, 18));
            change_fullscreen(store);
        }
    }
    if (evt.type == sfEvtKeyReleased && (evt.key.code == sfKeyRight ||
    evt.key.code == sfKeyLeft) && opt->movelock == 1)
        opt->movelock = 0;
}