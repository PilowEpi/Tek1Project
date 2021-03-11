/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** enemy_handling (CRUD)
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <math.h>
#include <stdlib.h>
#include "struct_defender.h"
#include "defender.h"
#include "dico_defender.h"

float get_enemy_distance(enemy_t *enemy, sfVector2f pos)
{
    float distance = sqrt(powf(pos.x*101 - enemy->pos.x, 2) +
        powf(pos.y*101 - enemy->pos.y, 2));
    return distance;
}

enemy_t *init_enemy(sfVector2i pos, enum enemy_type enemy_type, game_t *game)
{
    enemy_t *new = malloc(sizeof(enemy_t));
    sfVector2i tile = pos;
    sfVector2f coord = (sfVector2f) {(tile.x * 101), tile.y * 101 - 40};

    new->pos = coord;
    new->speed = (rand()%5)+2;
    new->health = 100 + (rand()%6 * 10 * (game->level->wave / 3));
    new->animation = copy_animation(game->texture->walk_ssa[enemy_type]);
    sfSprite_setPosition(new->animation->sprite, coord);
    return (new);
}

void add_enemy(sfVector2i pos, enum enemy_type enemy_type,
level_t *level, game_t *game)
{
    enemy_t **head = &(level->enemy_list);
    enemy_t *new = init_enemy(pos, enemy_type, game);

    new->attack_clock = sfClock_create();
    new->next = (*head);
    (*head) = new;
}

void destroy_enemy(enemy_t *tower)
{
    return;
}

void remove_enemy(enemy_t *enemy, level_t *level)
{
    enemy_t **head = &(level->enemy_list);
    enemy_t *tmp = *head;
    enemy_t *next = NULL;

    if (tmp != NULL && tmp == enemy) {
        *head = tmp->next;
        destroy_enemy(tmp);
        return;
    }
    while (tmp != NULL && tmp != enemy) {
        next = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL) return;
    next->next = tmp->next;
    destroy_enemy(tmp);
}