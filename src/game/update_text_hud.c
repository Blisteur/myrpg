/*
** EPITECH PROJECT, 2021
** update_txt_inv
** File description:
** file 1
*/

#include "rpg.h"

void update_txt_inv(int type, sfText *text)
{
    char tmp_set[4];

    my_strcpy(tmp_set, "000");
    tmp_set[2] = ((type % 10) + '0');
    tmp_set[1] = (((type / 10 ) % 10) + '0');
    tmp_set[0] = (((type / 100 ) % 10) + '0');
    sfText_setString(text, tmp_set);
}

void update_txt_stats(int type, sfText *text, char *str)
{
    char tmp_set[7];

    my_strcpy(tmp_set, str);
    my_strcat(tmp_set, " 00");
    tmp_set[5] = ((type % 10) + '0');
    tmp_set[4] = (((type / 10 ) % 10) + '0');
    sfText_setString(text, tmp_set);
}