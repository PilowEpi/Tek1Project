/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** tower_handling (CRUD)
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include "struct_defender.h"
#include "defender.h"
#include "dico_defender.h"

tower_t *init_tower(enum tower_type tower_type, game_t *game)
{
    tower_t *new = malloc(sizeof(tower_t));
    sfVector2i tile = game->level->tile_s;
    sfVector2f coord = (sfVector2f) {(tile.x * 101) + 10, tile.y * 101};
    sfIntRect text = (sfIntRect) {0, 0, 0, 0};

    text.width = tower_ss_info[tower_type].width;
    if (tower_type == MAGIC)
        coord.y = coord.y - 100;
    if (tower_type == SLOW)
        coord.y = coord.y - 30;
    if (tower_type == MAGIC || tower_type == SLOW)
        coord.x = coord.x - 8;
    new->sprite = sfSprite_create();
    sfSprite_setTexture(new->sprite, game->texture->towers[tower_type], 0);
    sfSprite_setPosition(new->sprite, coord);
    text.height = sfSprite_getTextureRect(new->sprite).height;
    sfSprite_setTextureRect(new->sprite, text);
    return (new);
}

void add_tower(sfVector2i pos, enum tower_type tower_type,
level_t *level, game_t *game)
{
    tower_t **head = &(level->tower_list);
    tower_t *new = init_tower(tower_type, game);

    new->type = tower_type;
    new->pos = pos;
    new->level = 1;
    new->attack_rate = 0.5;
    new->attack_clock = sfClock_create();
    new->next = (*head);
    (*head) = new;
}

void upgrade_tower(sfVector2i pos, tower_t *head)
{
    if (head == NULL)
        return;
    if (head->pos.x == pos.x && head->pos.y == pos.y) {
        head->level = head->level + 1;
        return;
    }
    return (upgrade_tower(pos, head->next));
}

void destroy_tower(tower_t *tower)
{
    return;
}