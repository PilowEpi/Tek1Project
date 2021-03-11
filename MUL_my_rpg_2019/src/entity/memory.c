/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** Memory handling free all type of things
*/

#include "rpg.h"

void free_body(sfConvexShape **body)
{
    for (int i = 0; body[i]; i++) {
        free(body[i]);
    }
    free(body);
}

void free_entity(entity_t *entity)
{
    free_body(entity->body);
    free(entity->stat);
    free(entity->loot_table);
    free(entity);
}