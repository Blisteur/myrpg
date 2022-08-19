/*
** EPITECH PROJECT, 2021
** dialogue
** File description:
** dialogue
*/

#include "rpg.h"

void diag_time_out(struct_t *store)
{
    sfRenderWindow_setView(store->win, store->cam);
    sfRenderWindow_drawText(store->win, store->game->dialogue->text, NULL);
    if ((store->game->clock->master_time.microseconds -
    store->game->dialogue->deltatime.microseconds) > 10000000) {
        remove_spe_obj(store->game->dialogue->last_call,
        store->game->dialogue->last_room_call);
        store->game->dialogue->lock = 0;
        store->game->dialogue->deltatime.microseconds = 0;
    }
}

static char *get_dialogue(char *filepath)
{
    FILE *stream =  fopen(filepath, "r");
    char *buff = NULL;
    size_t bytes = 0;

    getline(&buff, &bytes, stream);
    fclose(stream);
    return (buff);
}

void set_pnj_txt(struct_t *store, object_t *tmp2_ptr, game_room_t *tmp_ptr)
{
    char tmp_txt[] = "src/files/dialogue/dialogue1.txt";
    char *txt = NULL;

    store->game->dialogue->last_room_call = tmp_ptr;
    store->game->dialogue->last_call = tmp2_ptr;
    store->game->dialogue->deltatime.microseconds =
    store->game->clock->master_time.microseconds;
    store->game->dialogue->lock = 1;
    store->game->dialogue->pnj_txt++;
    tmp_txt[27] = (store->game->dialogue->pnj_txt + '0');
    txt = get_dialogue(tmp_txt);
    for (int i = 0; txt[i] != 0; i++)
        if (txt[i] == '|')
            txt[i] = '\n';
    sfText_setString(store->game->dialogue->text, txt);
    sfText_setPosition(store->game->dialogue->text,
    (sfVector2f) {tmp2_ptr->obj->pos.x - 160, tmp2_ptr->obj->pos.y + 160});
    free(txt);
}