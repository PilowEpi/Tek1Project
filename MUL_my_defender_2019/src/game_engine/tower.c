/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** tower_handling (CRUD)
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "struct_defender.h"
#include "defender.h"
#include "dico_defender.h"

void remove_tower(sfVector2i pos, level_t *level)
{
    tower_t **head = &(level->tower_list);
    tower_t *tmp = *head;
    tower_t *next = NULL;

    if (tmp != NULL && (tmp->pos.x == pos.x && tmp->pos.y == pos.y)) {
        *head = tmp->next;
        destroy_tower(tmp);
        return;
    }
    while (tmp != NULL && !(tmp->pos.x == pos.x && tmp->pos.y == pos.y)) {
        next = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL) return;
    next->next = tmp->next;
    destroy_tower(tmp->next);
}

int is_tile_tower(sfVector2i pos, tower_t *head)
{
    if (head == NULL)
        return (0);
    if (head->pos.x == pos.x && head->pos.y == pos.y) {
        return (1);
    }
    return (is_tile_tower(pos, head->next));
}

tower_t *get_tower(sfVector2i pos, tower_t *head)
{
    if (head == NULL)
        return (NULL);
    if (head->pos.x == pos.x && head->pos.y == pos.y) {
        return (head);
    }
    return (get_tower(pos, head->next));
}