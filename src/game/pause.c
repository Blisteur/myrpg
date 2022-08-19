/*
** EPITECH PROJECT, 2021
** pause
** File description:
** file 1
*/

#include "rpg.h"

void display_pause(sfRenderWindow *win, struct_t *store)
{
    sfRenderWindow_setView(store->win, store->cam);
    sfRenderWindow_drawSprite(win, store->game->pause->pause->spr, NULL);
    sfSprite_setPosition(store->game->pause->select->spr,
    store->game->pause->pos[store->game->pause->selected]);
    sfRenderWindow_drawSprite(win, store->game->pause->select->spr, NULL);
}

void pause_parser(struct_t *store)
{
    int sel = store->game->pause->selected;

    if ((store->evt.key.code == sfKeySpace ||
    store->evt.key.code == sfKeyEnter) &&
    store->evt.type == sfEvtKeyReleased) {
        if (sel == 0) {
            audio_run_sound(store, SOUND_SELECT);
            store->game->mode = MODE_GAME;
        } if (sel == 1) {
            audio_run_sound(store, SOUND_SELECT);
            store->game->stop = 1;
        } if (sel == 2) {
            audio_run_sound(store, SOUND_SELECT);
            sfRenderWindow_close(store->win);
        }
    }
}

void pause_selecter(struct_t *store)
{
    if (store->evt.type == sfEvtKeyReleased &&
    store->evt.key.code == sfKeyUp && store->game->pause->selected > 0) {
        store->game->pause->selected--;
        sfSprite_setPosition(store->game->pause->select->spr,
        store->game->pause->pos[store->game->pause->selected]);
        audio_run_sound(store, SOUND_CURSOR);
    } if (store->evt.type == sfEvtKeyReleased &&
    store->evt.key.code == sfKeyDown && store->game->pause->selected < 2) {
        store->game->pause->selected++;
        sfSprite_setPosition(store->game->pause->select->spr,
        store->game->pause->pos[store->game->pause->selected]);
        audio_run_sound(store, SOUND_CURSOR);
    }
}

void pause_event(struct_t *store)
{
    if (store->game->mode == MODE_PAUSE) {
        pause_selecter(store);
        pause_parser(store);
    }
    if ((store->evt.key.code == sfKeyEscape
    && store->evt.type == sfEvtKeyReleased)
    || store->evt.type == sfEvtLostFocus) {
        if (store->game->mode == MODE_GAME) {
            store->game->mode = MODE_PAUSE;
            sfMusic_pause(store->audio->master_music[MUSIC_TYPE1]);
            sfView_setSize(store->cam, (sfVector2f) {1920, 1080});
            audio_run_sound(store, SOUND_PAUSE);
        } else if (store->game->mode == MODE_PAUSE
        && store->evt.type != sfEvtLostFocus) {
            store->game->mode = MODE_GAME;
            audio_run_music(store, MUSIC_TYPE1);
            sfView_setSize(store->cam, store->game->map->zoom_basement);
            audio_run_sound(store, SOUND_PAUSE);
        }
    }
}

void pause_mode(struct_t *store)
{
    sfVector2f pos[3] = {{650, 300}, {700, 460}, {780, 650}};

    store->game->clock->time_freeze = 0;
    store->game->pause->pause->pos = sfView_getCenter(store->cam);
    store->game->pause->pause->pos.x -= 960;
    store->game->pause->pause->pos.y -= 540;
    for (int i = 0; i != 3; i++) {
        store->game->pause->pos[i].x = pos[i].x +
        store->game->pause->pause->pos.x;
        store->game->pause->pos[i].y = pos[i].y +
        store->game->pause->pause->pos.y;
    }
    sfSprite_setPosition(store->game->pause->pause->spr,
    store->game->pause->pause->pos);
}