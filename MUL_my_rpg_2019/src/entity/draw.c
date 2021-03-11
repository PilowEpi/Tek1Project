/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** Drawing entities function !
*/

#include "engine.h"

int draw_entity(sfRenderWindow *window, entity_t *entity)
{
    if (!entity || !entity->body)
        return (1);
    for (int i = 0; entity->body && entity->body[i]; i++) {
        sfRenderWindow_drawConvexShape(window, entity->body[i], 0);
    }
    return (0);
}