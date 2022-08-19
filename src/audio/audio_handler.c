/*
** EPITECH PROJECT, 2021
** audio_handler
** File description:
** file 1
*/

#include "rpg.h"

void menu_audio(struct_t *store, int type)
{
    if (type == 1) {
        store->audio->master_music[MUSIC_MENU]
        = sfMusic_createFromFile("src/assets/menu.ogg");
        audio_run_music(store, MUSIC_MENU);
    } else {
        sfMusic_destroy(store->audio->master_music[MUSIC_MENU]);
    }
}

void intro_audio(struct_t *store, int type)
{
    if (type == 1) {
        store->audio->master_music[MUSIC_INTRO]
        = sfMusic_createFromFile("src/assets/intro.ogg");
        audio_run_music(store, MUSIC_INTRO);
    } else {
        sfMusic_destroy(store->audio->master_music[MUSIC_INTRO]);
    }
}

static void game_audio_sound(struct_t *store)
{
    store->audio->master_sound_buffer[SOUND_PAUSE]
    = sfSoundBuffer_createFromFile("src/assets/pause.ogg");
    store->audio->master_sound_buffer[SOUND_ATTACK]
    = sfSoundBuffer_createFromFile("src/assets/attack.ogg");
    store->audio->master_sound[SOUND_PAUSE] = sfSound_create();
    store->audio->master_sound[SOUND_ATTACK] = sfSound_create();
    sfSound_setBuffer(store->audio->master_sound[SOUND_PAUSE]
    , store->audio->master_sound_buffer[SOUND_PAUSE]);
    sfSound_setBuffer(store->audio->master_sound[SOUND_ATTACK]
    , store->audio->master_sound_buffer[SOUND_ATTACK]);
    sfSound_setVolume(store->audio->master_sound[SOUND_PAUSE]
    , store->settings->volume[1]);
    sfSound_setVolume(store->audio->master_sound[SOUND_ATTACK]
    , store->settings->volume[1]);
}

void game_audio(struct_t *store, int type)
{
    if (type == 1) {
        store->audio->master_music[MUSIC_TYPE1]
        = sfMusic_createFromFile("src/assets/music1.ogg");
        store->audio->master_music[MUSIC_TYPE2]
        = sfMusic_createFromFile("src/assets/music2.ogg");
        game_audio_sound(store);
    } else {
        sfMusic_destroy(store->audio->master_music[MUSIC_TYPE1]);
        sfMusic_destroy(store->audio->master_music[MUSIC_TYPE2]);
        sfSoundBuffer_destroy(store->audio->master_sound_buffer[SOUND_PAUSE]);
        sfSoundBuffer_destroy(store->audio->master_sound_buffer[SOUND_ATTACK]);
        sfSound_destroy(store->audio->master_sound[SOUND_PAUSE]);
        sfSound_destroy(store->audio->master_sound[SOUND_ATTACK]);
    }
}