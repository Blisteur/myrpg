/*
** EPITECH PROJECT, 2020
** src
** File description:
** src
*/

#include "rpg.h"

sfVector2f vec(int x, int y)
{
    sfVector2f vec = {x, y};

    return (vec);
}

sfIntRect rect(int left, int top, int width, int height)
{
    sfIntRect rect = {left, top, width, height};

    return (rect);
}

element_t *create_elem(char *filepath, sfVector2f pos, sfIntRect rect,
                        int scale)
{
    element_t *obj = malloc(sizeof(element_t));

    obj->pos = pos;
    obj->rect = rect;
    obj->tex = sfTexture_createFromFile(filepath, NULL);
    obj->spr = sfSprite_create();
    sfSprite_setTexture(obj->spr, obj->tex, sfFalse);
    sfSprite_setTextureRect(obj->spr, rect);
    sfSprite_setPosition(obj->spr, pos);
    sfSprite_scale(obj->spr, vec(scale, scale));
    return (obj);
}

void destroy_elem(element_t *obj)
{
    sfSprite_destroy(obj->spr);
    sfTexture_destroy(obj->tex);
    free(obj);
}