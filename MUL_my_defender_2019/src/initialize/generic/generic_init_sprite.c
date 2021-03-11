/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Funct of initialize sprite
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "struct_defender.h"
#include "defender.h"

int init_sprite_texture(sprite_t *sprite, char *pathname)
{
    sprite->texture = sfTexture_createFromFile(pathname, NULL);
    if (!sprite->texture)
        return (84);
    return (0);
}

int create_sprite(sprite_t *sprite)
{
    sprite->img = sfSprite_create();
    if (!sprite->img)
        return (84);
    sfSprite_setTexture(sprite->img, sprite->texture, sfTrue);
    return (0);
}

void init_vector(sprite_t *sprite, float x, float y)
{
    sfVector2f base_vect = {x, y};
    sprite->vect = base_vect;
}

void init_init_vector(sprite_t *sprite, float x, float y)
{
    sfVector2f base_vect = {x, y};
    sprite->init = base_vect;
}

portal_t *init_portal(sfVector2i pos, game_t *game)
{
    portal_t *new = malloc(sizeof(portal_t));
    sfVector2i tile = pos;
    sfVector2f coord = (sfVector2f) {(tile.x * 101), tile.y * 101 - 40};

    new->pos = pos;
    new->sprite = sfSprite_create();
    new->spawn_rate = 1 + rand()%3;
    sfSprite_setTexture(new->sprite, game->texture->portal, 0);
    sfSprite_setPosition(new->sprite, coord);
    return (new);
}