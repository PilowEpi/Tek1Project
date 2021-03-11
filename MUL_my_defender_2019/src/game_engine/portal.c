/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** portal_handling (CRUD)
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include "struct_defender.h"
#include "defender.h"
#include "dico_defender.h"

void add_portal(sfVector2i pos, level_t *level, game_t *game)
{
    portal_t **head = &(level->portal_list);
    portal_t *new = init_portal(pos, game);

    new->spawn = sfClock_create();
    new->next = (*head);
    (*head) = new;
}

void destroy_portal(portal_t *portal)
{
    free(portal);
    return;
}

void remove_portal(sfVector2i pos, level_t *level)
{
    portal_t **head = &(level->portal_list);
    portal_t *tmp = *head;
    portal_t *next = NULL;

    if (tmp != NULL && (tmp->pos.x == pos.x && tmp->pos.y == pos.y)) {
        *head = tmp->next;
        destroy_portal(tmp);
        return;
    }
    while (tmp != NULL && !(tmp->pos.x == pos.x && tmp->pos.y == pos.y)) {
        next = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL) return;
    next->next = tmp->next;
    destroy_portal(tmp->next);
}

int is_tile_portal(sfVector2i pos, portal_t *head)
{
    if (head == NULL)
        return (0);
    if (head->pos.x == pos.x && head->pos.y == pos.y) {
        return (1);
    }
    return (is_tile_portal(pos, head->next));
}

portal_t *get_portal(sfVector2i pos, portal_t *head)
{
    if (head == NULL)
        return (NULL);
    if (head->pos.x == pos.x && head->pos.y == pos.y) {
        return (head);
    }
    return (get_portal(pos, head->next));
}