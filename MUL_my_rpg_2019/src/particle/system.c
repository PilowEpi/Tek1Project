/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Particle system handling
*/

#include <stdlib.h>

#include "particle.h"

syst_t *create_system(void)
{
    syst_t *system = malloc(sizeof(syst_t));
    descriptor_t *desc = create_descriptor();

    if (!system || !desc)
        return (0);
    system->desc = desc;
    system->pt_head = 0;
    system->timer = 0;
    system->tex = sfTexture_create(1, 1);
    system->sprite = sfSprite_create();
    sfSprite_setTexture(system->sprite, system->tex, sfTrue);
    return (system);
}

void append_particle(syst_t *system, point_t *particle)
{
    particle->next = system->pt_head;
    if (system->pt_head)
        system->pt_head->prev = particle;
    system->pt_head = particle;
}

void delete_particle(syst_t *system, point_t *particle)
{
    if (particle->next)
        particle->next->prev = particle->prev;
    if (particle->prev)
        particle->prev->next = particle->next;
    if (system->pt_head == particle)
        system->pt_head = 0;
    free(particle);
}
