/*
** EPITECH PROJECT, 2021
** get inputs
** File description:
** file 1
*/

#include "rpg.h"

static void defaut_inputs(settings_t *settings)
{
    settings->inputs[INPUT_UP] = sfKeyZ;
    settings->inputs[INPUT_DOWN] = sfKeyS;
    settings->inputs[INPUT_LEFT] = sfKeyQ;
    settings->inputs[INPUT_RIGHT] = sfKeyD;
    settings->inputs[INPUT_HIT_UP] = sfKeyUp;
    settings->inputs[INPUT_HIT_DOWN] = sfKeyDown;
    settings->inputs[INPUT_HIT_LEFT] = sfKeyLeft;
    settings->inputs[INPUT_HIT_RIGHT] = sfKeyRight;
    settings->inputs[INPUT_BOW] = sfKeyA;
    settings->inputs[INPUT_BOMB] = sfKeyE;
}

static FILE *open_inputs_file(struct_t *store)
{
    FILE *fp = NULL;

    fp = fopen("src/files/inputs.txt", "r");
    if (fp == NULL) {
        defaut_inputs(store->settings);
        return (NULL);
    }
    return (fp);
}

void get_inputs(struct_t *store)
{
    char *buff = NULL;
    size_t buff_size = 0;
    FILE *fp = open_inputs_file(store);
    int lenght = 0;

    if (fp == NULL) {
        return;
    }
    for (int nb = 0; nb < 10; nb += 1) {
        lenght =  getline(&buff, &buff_size, fp);
        if (buff == NULL || lenght == -1) {
            defaut_inputs(store->settings);
            fclose(fp);
            return;
        }
        store->settings->inputs[nb] = my_getnbr(buff);
        buff_size = 0;
        free(buff);
    }
    fclose(fp);
}