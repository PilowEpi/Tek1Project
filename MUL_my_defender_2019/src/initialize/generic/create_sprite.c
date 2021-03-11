/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** create_sprite
*/

#include "struct_defender.h"
#include "defender.h"

int init_sprite(sprite_t *sprite, const init_sprite_t *sprite_data)
{
    if (init_sprite_texture(sprite, sprite_data->path) == 84) {
        return (84);
    }
    if (create_sprite(sprite) == 84) {
        return (84);
    }
    init_vector(sprite, sprite_data->x_coor, sprite_data->y_coor);
    return (0);
}
