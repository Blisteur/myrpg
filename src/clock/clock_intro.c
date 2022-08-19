/*
** EPITECH PROJECT, 2021
** clock
** File description:
** file 1
*/

#include "rpg.h"

void change_values(struct_t *store, int time, int max[6])
{
    sfIntRect rect = {961, 235, 686, 134};

    if (time == 100) {
        store->intro->state++;
    } else if (store->intro->text->rect.left == max[store->intro->state - 1]) {
        if (store->intro->state == 3) {
            store->intro->text->rect = rect;
            sfSprite_setTextureRect(store->intro->text->spr, rect);
            sfSprite_setPosition(store->intro->text->spr, vec(274, 406));
        }
        store->intro->state++;
    } if (store->intro->state > 6)
        store->intro->state = 0;
}

void anim_intro(struct_t *store)
{
    int time = 1;
    int move[6] = {704, 0, -704, 686, 0, -686};
    int max[6] = {4481, 0, 961, 4391, 0, 961};

    if (store->intro->state == 2 || store->intro->state == 5)
        time = 100;
    store->intro->time++;
    if (store->intro->time == time) {
        store->intro->text->rect.left += move[store->intro->state - 1];
        sfSprite_setTextureRect(store->intro->text->spr,
        store->intro->text->rect);
        store->intro->time = 0;
        change_values(store, time, max);
    }
}

void clock_intro(game_clock_t *clock, struct_t *store)
{
    clock->master_time = sfClock_getElapsedTime(clock->master_clock);
    clock->delta_time.microseconds
    = (clock->master_time.microseconds
    - clock->previous_master_time.microseconds);
    clock->previous_master_time.microseconds = clock->master_time.microseconds;
    clock->anim_time.microseconds += clock->delta_time.microseconds;
    if (clock->anim_time.microseconds >= 100000) {
        while (clock->anim_time.microseconds >= 100000) {
            anim_intro(store);
            clock->anim_time.microseconds -= 100000;
        }
    }
}