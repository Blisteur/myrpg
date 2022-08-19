/*
** EPITECH PROJECT, 2021
** init_dialogue
** File description:
** init_dialogue
*/

#include "rpg.h"

void destroy_dialogue(struct_t *store)
{
    sfText_destroy(store->game->dialogue->text);
    sfFont_destroy(store->game->dialogue->font);
    free(store->game->dialogue);
}

void init_dialogue(struct_t *store)
{
    store->game->dialogue = malloc(sizeof(dialogue_t));
    store->game->dialogue->last_call = NULL;
    store->game->dialogue->last_room_call = NULL;
    store->game->dialogue->pnj_txt = 0;
    store->game->dialogue->lock = 0;
    store->game->dialogue->text = sfText_create();
    store->game->dialogue->font
    = sfFont_createFromFile("src/files/game/gamefont.ttf");
    sfText_setFont(store->game->dialogue->text, store->game->dialogue->font);
}