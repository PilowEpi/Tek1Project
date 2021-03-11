/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** enemy_handling (CRUD)
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <math.h>
#include "struct_defender.h"
#include "defender.h"
#include "dico_defender.h"

int is_tile_enemy(sfVector2i pos, enemy_t *head)
{
    if (head == NULL)
        return (0);
    if (head->pos.x == pos.x && head->pos.y == pos.y) {
        return (1);
    }
    return (is_tile_enemy(pos, head->next));
}

enemy_t *get_enemy(sfVector2i pos, enemy_t *head)
{
    if (head == NULL)
        return (NULL);
    if (head->pos.x == pos.x && head->pos.y == pos.y) {
        return (head);
    }
    return (get_enemy(pos, head->next));
}