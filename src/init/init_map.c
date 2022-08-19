/*
** EPITECH PROJECT, 2021
** init_map
** File description:
** init_map
*/

#include "rpg.h"

static void set_room_spawn(struct_t *store, sfVector2f pos)
{
    sfView_setCenter(store->cam, (sfVector2f) {pos.x + 960, pos.y + 540});
    sfView_setCenter(store->mini_maps
    , (sfVector2f) {pos.x + 960, pos.y + 540});
    store->game->player->pos = (sfVector2f) {pos.x + 960, pos.y + 540};
    store->game->player->hit_box.left = (store->game->player->pos.x + 6);
    store->game->player->hit_box.top = (store->game->player->pos.y + 25);
    store->game->player->room_id = store->game->map->first_room->id;
}

static void create_room_linklist(struct_t *store, char *buff
                            , void (*ptr[7]), sfVector2f pos)
{
    for (int tmp = 0; buff[tmp]; tmp += 1) {
        if (buff[tmp] != '0' && buff[tmp] != '\n') {
            store->game->map->first_room = add_room(store,
            store->game->map->first_room, pos, ptr[(buff[tmp] - '0')]);
        }
        if (buff[tmp] == '1') {
            set_room_spawn(store, pos);
        }
        pos.x += 1920;
        if (buff[tmp] == '\n') {
            pos.x = 0;
            pos.y += 1080;
        }
    }
}

static void create_room(struct_t *store, char *file, int nb)
{
    int fd = open(file, O_RDONLY);
    char buff[nb + 1];
    void (*ptr[7]);
    sfVector2f pos = {0, 0};

    ptr[0] = NULL;
    ptr[1] = init_spawn_room;
    ptr[2] = init_basic_room;
    ptr[3] = init_special_room;
    ptr[4] = init_item_room;
    ptr[5] = init_boss_room;
    ptr[6] = init_zelda_room;
    buff[nb] = '\0';
    read(fd, buff, nb);
    create_room_linklist(store, buff, ptr, pos);
    close(fd);
}

void create_level(struct_t *store)
{
    if (store->game->map->level == 1)
        create_room(store, "src/files/maps/basement1.txt", 89);
    if (store->game->map->level == 2)
        create_room(store, "src/files/maps/basement2.txt", 239);
    if (store->game->map->level == 3)
        create_room(store, "src/files/maps/basement3.txt", 461);
    if (store->game->map->level == 4)
        create_room(store, "src/files/maps/basement4.txt", 649);
    create_door(store);
}

void init_map(struct_t *store)
{
    game_room_t *tmp = NULL;
    char tmp_txt[] = "src/files/maps/room1.txt";
    store->game->map = malloc(sizeof(game_basement_t));

    store->game->map->level = 1;
    store->game->map->nb_room = 0;
    store->game->map->changing_room = 0;
    store->game->map->anim_changing_room.microseconds = 0;
    store->game->map->changing_basement = 0;
    store->game->map->anim_changing_basement.microseconds = 0;
    store->game->map->zoom_basement = (sfVector2f) {1920, 1080};
    store->game->map->changin_room_pos = '0';
    store->game->map->first_room = NULL;
    create_level(store);
    tmp = store->game->map->first_room;
    for (int nb = 0; nb < store->game->map->nb_room; nb += 1) {
        tmp_txt[19] = (tmp->seed + '0');
        read_map(tmp_txt, tmp);
        tmp = tmp->next;
    }
}