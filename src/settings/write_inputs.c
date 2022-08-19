/*
** EPITECH PROJECT, 2021
** write_settings
** File description:
** file 1
*/

#include "rpg.h"

static void write_screen_inputs(struct_t *store, int fd)
{
    for (int nb = 0; nb < 10; nb += 1) {
        my_putnbr_to_file(store->settings->inputs[nb], fd);
        my_putstr_to_file(";\n", fd);
    }
}

void write_inputs(struct_t *store)
{
    int fd = open("src/files/inputs.txt", O_WRONLY | O_CREAT, 00666);

    if (fd == -1)
        return;
    write_screen_inputs(store, fd);
    close(fd);
}