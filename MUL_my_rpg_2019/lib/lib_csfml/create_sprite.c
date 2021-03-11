/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_sprite
*/

#include "lib_csfml.h"
#include "struct_csfml.h"

int init_sprite_texture(sprite_t *sprite, char *pathname)
{
    sprite->texture = sfTexture_createFromFile(pathname, NULL);
    if (!sprite->texture)
        return (-1);
    return (0);
}

void init_vector(sprite_t *sprite, float x, float y)
{
    sfVector2f base_vect = {x, y};

    sprite->vect = base_vect;
}

int create_sprite(sprite_t *sprite)
{
    sprite->img = sfSprite_create();
    if (!sprite->img)
        return (-1);
    sfSprite_setTexture(sprite->img, sprite->texture, sfTrue);
    return (0);
}

int init_sprite(sprite_t *sprite, const init_sprite_t *sprite_data)
{
    if (init_sprite_texture(sprite, sprite_data->path) == -1) {
        return (-1);
    }
    if (create_sprite(sprite) == -1) {
        return (-1);
    }
    init_vector(sprite, sprite_data->x_coor, sprite_data->y_coor);
    return (0);
}
