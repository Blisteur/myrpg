/*
** EPITECH PROJECT, 2021
** write_settings
** File description:
** file 1
*/

#include "rpg.h"

static void write_help_settings(int fd)
{
    my_putstr_to_file("\n/--------------------HELP-", fd);
    my_putstr_to_file("SETTINGS------------------------\\\n", fd);
    my_putstr_to_file("RESOLUTION:{width*height}\n", fd);
    my_putstr_to_file("FULLSCREEN:{0 or 1} 0 for false 1 for true\n", fd);
    my_putstr_to_file("BITS_PER_PIXEL:{number of bits per pixel}\n", fd);
    my_putstr_to_file("FPS:{number of frames per second}\n", fd);
    my_putstr_to_file("MASTER_SOUND:{number between 0 ", fd);
    my_putstr_to_file("and 100 percent for music volume}\n", fd);
    my_putstr_to_file("EFFECT_SOUND:{number between 0 ", fd);
    my_putstr_to_file("and 100 percent for effect volume}\n", fd);
    my_putstr_to_file("/----------------------------", fd);
    my_putstr_to_file("-----------------------------\\", fd);
}

static void write_screen_settings(struct_t *store, int fd)
{
    my_putstr_to_file("RESOLUTION:{", fd);
    my_putnbr_to_file(store->settings->resolution[0], fd);
    my_putchar_to_file('*', fd);
    my_putnbr_to_file(store->settings->resolution[1], fd);
    my_putstr_to_file("} //default 1920*1080\n", fd);
    my_putstr_to_file("FULLSCREEN:{", fd);
    my_putnbr_to_file(store->settings->fullscreen, fd);
    my_putstr_to_file("} //default 0\n", fd);
    my_putstr_to_file("BITS_PER_PIXEL:{", fd);
    my_putnbr_to_file(store->settings->bpp, fd);
    my_putstr_to_file("} //default 32\n", fd);
    my_putstr_to_file("FPS:{", fd);
    my_putnbr_to_file(store->settings->fps, fd);
    my_putstr_to_file("} //default 60\n", fd);
}

static void write_sound_settings(struct_t *store, int fd)
{
    my_putstr_to_file("MASTER_SOUND:{", fd);
    my_putnbr_to_file(store->settings->volume[0], fd);
    my_putstr_to_file("} //default 100\n", fd);
    my_putstr_to_file("EFFECT_SOUND:{", fd);
    my_putnbr_to_file(store->settings->volume[1], fd);
    my_putstr_to_file("} //default 100\n", fd);
}

void write_settings(struct_t *store)
{
    int fd = open("src/files/settings.txt", O_WRONLY | O_CREAT, 00666);

    if (fd == -1)
        return;
    write_screen_settings(store, fd);
    write_sound_settings(store, fd);
    write_help_settings(fd);
    close(fd);
}