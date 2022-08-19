/*
** EPITECH PROJECT, 2021
** set_volume_settings
** File description:
** file 2 ->set_settings
*/

#include "rpg.h"

void set_master_volume(struct_t *store, char *buff)
{
    int parsing = 0;

    for (; buff[parsing] != '\n'; parsing += 1) {
        if (buff[parsing] == '/' && buff[parsing + 1] == '/')
            break;
        if (buff[parsing] == '{') {
            store->settings->volume[0] = my_getnbr(buff + parsing + 1);
            break;
        }
    }
    if (store->settings->volume[0] > 100)
        store->settings->volume[0] = 100;
}

void set_sound_volume(struct_t *store, char *buff)
{
    int parsing = 0;

    for (; buff[parsing] != '\n'; parsing += 1) {
        if (buff[parsing] == '/' && buff[parsing + 1] == '/')
            break;
        if (buff[parsing] == '{') {
            store->settings->volume[1] = my_getnbr(buff + parsing + 1);
            break;
        }
    }
    if (store->settings->volume[1] > 100)
        store->settings->volume[1] = 100;
}