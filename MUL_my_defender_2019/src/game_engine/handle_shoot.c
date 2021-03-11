/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** handle_shoot
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include "struct_defender.h"
#include "defender.h"
#include "my.h"
#include "dico_defender.h"

void destroy_shoot(shoot_t *shoot)
{
    free(shoot);
    return;
}

void remove_shoot(shoot_t **list, shoot_t *key)
{
    shoot_t *temp = *list;
    shoot_t *prev = NULL;

    if (temp != NULL && temp == key) {
        *list = temp->next;
        destroy_shoot(temp);
        return;
    }
    while (temp != NULL && temp != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    destroy_shoot(temp);
}

void play_shoot(shoot_t **list, sfRenderWindow *window)
{
    sfVector2f pos;

    shoot_t *tmp = *list;
    while (tmp != NULL) {
        pos = get_newposition(tmp->from, tmp->to->pos, 5);
        sfSprite_setPosition(tmp->sprite, pos);
        tmp->from = pos;
        sfRenderWindow_drawSprite(window, tmp->sprite, 0);
        if (pos.x == tmp->to->pos.x && tmp->to->pos.y == pos.y) {
            tmp->to->health = tmp->to->health - 10 * tmp->tower->level;
            remove_shoot(list, tmp);
        }
        tmp = tmp->next;
    }
}

void shoot(tower_t *tower, game_t *game, sfVector2f from, enemy_t *enemy)
{
    shoot_t *shoot = malloc(sizeof(shoot_t));
    enum tower_type type = tower->type;

    shoot->sprite = sfSprite_create();
    if (tower->type == ARCHER)
        sfSound_play(game->sound_effect[0]);
    if (tower->type == BOMB)
        sfSound_play(game->sound_effect[1]);
    sfSprite_setTexture(shoot->sprite, game->texture->projectile[type], 0);
    shoot->from = from;
    shoot->tower = tower;
    shoot->to = enemy;
    shoot->next = game->level->shoot;
    game->level->shoot = shoot;
}