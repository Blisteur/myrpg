/*
** EPITECH PROJECT, 2021
** destroy_menu
** File description:
** destroy_menu
*/

#include "rpg.h"

void destroy_menu_cont(controls_t *cont)
{
    destroy_elem(cont->controls);
    destroy_elem(cont->select);
    sfFont_destroy(cont->font);
    for (int nb = 0; nb < 10; nb += 1) {
        sfText_destroy(cont->key[nb]);
    }
    free(cont);
}

void destroy_menu_opt(option_t *opt)
{
    destroy_elem(opt->options);
    destroy_elem(opt->res);
    destroy_elem(opt->mus_bar);
    destroy_elem(opt->sfx_bar);
    destroy_elem(opt->full_on);
    destroy_elem(opt->select);
    destroy_elem(opt->tuto);
    free(opt);
}

void destroy_menu(struct_t *store)
{
    destroy_elem(store->menu->main);
    destroy_elem(store->menu->logo);
    destroy_elem(store->menu->menu);
    destroy_elem(store->menu->cont);
    destroy_elem(store->menu->select);
    destroy_menu_opt(store->menu->opt);
    destroy_menu_cont(store->menu->contr);
    menu_audio(store, 2);
    free(store->menu);
}