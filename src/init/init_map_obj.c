/*
** EPITECH PROJECT, 2021
** map
** File description:
** file 1
*/

#include "rpg.h"

static void init_ptr_tab(void (*ptr[505]))
{
    ptr[OBJ_VOID] = init_void_obj;
    ptr[OBJ_SPIKE] = init_spike_obj;
    ptr[OBJ_ROCK] = init_rock_obj;
    ptr[OBJ_FIRE] = init_fire_obj;
    ptr[OBJ_POOP] = init_poop_obj;
    ptr[OBJ_METAL] = init_metal_obj;
    ptr[OBJ_KEY] = init_key_obj;
    ptr[OBJ_BOMB] = init_bomb_obj;
    ptr[OBJ_COIN] = init_coin_obj;
    ptr[OBJ_PNJ] = init_pnj_obj;
    ptr[OBJ_MOB1] = init_gaper_obj;
    ptr[OBJ_MOB2] = init_spider_obj;
    ptr[OBJ_MOB3] = init_fly_obj;
    ptr[OBJ_MOB4] = init_zelda_obj;
}

void create_map(sfVector2f *tmp_pos, char *buff, int len, game_room_t *room)
{
    int nbr = 0;
    int i = 0;
    int tmp = 0;
    void (*ptr[505]) = { NULL };

    init_ptr_tab(ptr);
    for (int j = 0; tmp < len; j++) {
        nbr = my_getnbr(buff + tmp);
        if (nbr != 0)
            room->last_create = add_room_object(room, room->last_create
            , (sfVector2f) {tmp_pos->x, tmp_pos->y}, ptr[nbr]);
        i = my_nbrlen(nbr, 10);
        if (i == 0)
            i = 1;
        tmp += i + 1;
        tmp_pos->x += 116;
    }
}

void read_map(char *filepath, game_room_t *room)
{
    FILE *stream = fopen(filepath, "r");
    char *buff = NULL;
    size_t buff_size = 0;
    int bytes = 0;
    sfVector2f tmp_pos = {(room->back->pos.x + 204)
    , (room->back->pos.y + 176)};

    if (stream == NULL)
        return;
    while (bytes != -1) {
        bytes = getline(&buff, &buff_size, stream);
        create_map(&tmp_pos, buff, bytes, room);
        tmp_pos.x = (room->back->pos.x + 204);
        tmp_pos.y += 96;
    }
    free(buff);
    fclose(stream);
}