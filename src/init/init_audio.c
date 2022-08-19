/*
** EPITECH PROJECT, 2021
** init audio
** File description:
** file 1
*/

#include "rpg.h"

void init_audio(struct_t *store)
{
    store->audio = malloc(sizeof(audio_t));

    store->audio->master_sound_buffer[SOUND_CURSOR]
    = sfSoundBuffer_createFromFile("src/assets/cursor.ogg");
    store->audio->master_sound_buffer[SOUND_SELECT]
    = sfSoundBuffer_createFromFile("src/assets/select.ogg");
    store->audio->master_sound[SOUND_CURSOR] = sfSound_create();
    store->audio->master_sound[SOUND_SELECT] = sfSound_create();
    sfSound_setBuffer(store->audio->master_sound[SOUND_CURSOR]
    , store->audio->master_sound_buffer[SOUND_CURSOR]);
    sfSound_setBuffer(store->audio->master_sound[SOUND_SELECT]
    , store->audio->master_sound_buffer[SOUND_SELECT]);
    sfSound_setVolume(store->audio->master_sound[SOUND_CURSOR]
    , store->settings->volume[1]);
    sfSound_setVolume(store->audio->master_sound[SOUND_SELECT]
    , store->settings->volume[1]);
}

void destroy_audio(struct_t *store)
{
    sfSoundBuffer_destroy(store->audio->master_sound_buffer[SOUND_CURSOR]);
    sfSoundBuffer_destroy(store->audio->master_sound_buffer[SOUND_SELECT]);
    sfSound_destroy(store->audio->master_sound[SOUND_CURSOR]);
    sfSound_destroy(store->audio->master_sound[SOUND_SELECT]);
    free(store->audio);
}