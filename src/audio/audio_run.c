/*
** EPITECH PROJECT, 2021
** audio run
** File description:
** file 1
*/

#include "rpg.h"

void audio_run_sound(struct_t *store, sound_type type)
{
    sfSound_play(store->audio->master_sound[type]);
}

void audio_run_music(struct_t *store, music_type type)
{
    sfMusic_play(store->audio->master_music[type]);
    sfMusic_setLoop(store->audio->master_music[type], sfTrue);
    sfMusic_setVolume(store->audio->master_music[type]
    , store->settings->volume[0]);
}