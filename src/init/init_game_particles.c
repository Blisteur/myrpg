/*
** EPITECH PROJECT, 2021
** init game particles
** File description:
** file 1
*/

#include "rpg.h"

void init_particles(struct_t *store)
{
    store->game->particles = malloc(sizeof(particles_handler_t));

    store->game->particles->first_smoke = NULL;
    store->game->particles->time_smoke.microseconds = 0;
}

void destroy_particles(struct_t *store)
{
    particles_t *to_free = store->game->particles->first_smoke;

    while (store->game->particles->first_smoke != NULL) {
        to_free = store->game->particles->first_smoke;
        store->game->particles->first_smoke
        = store->game->particles->first_smoke->next;
        destroy_elem(to_free->p);
        free(to_free);
    }
    free(store->game->particles);
}