/*
** EPITECH PROJECT, 2021
** anim_mobs
** File description:
** anim_mobs
*/

#include "rpg.h"

void anim_gaper(object_t *mob)
{
    mob->obj->rect.left += 28;
    if (mob->obj->rect.left >= 253)
        mob->obj->rect.left = 0;
    sfSprite_setTextureRect(mob->obj->spr, mob->obj->rect);
}

void anim_spider(object_t *mob)
{
    mob->obj->rect.left += 28;
    if (mob->obj->rect.left >= 141)
        mob->obj->rect.left = 0;
    sfSprite_setTextureRect(mob->obj->spr, mob->obj->rect);
}

void anim_fly(object_t *mob)
{
    mob->obj->rect.left += 28;
    if (mob->obj->rect.left >= 29)
        mob->obj->rect.left = 0;
    sfSprite_setTextureRect(mob->obj->spr, mob->obj->rect);
}

void anim_zelda(object_t *mob)
{
    mob->obj->rect.left += 28;
    if (mob->obj->rect.left >= 253)
        mob->obj->rect.left = 0;
    sfSprite_setTextureRect(mob->obj->spr, mob->obj->rect);
}