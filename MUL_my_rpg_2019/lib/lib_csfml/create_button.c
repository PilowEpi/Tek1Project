/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_button
*/

#include "lib_csfml.h"
#include "struct_csfml.h"

int init_button_data(button_t *button, const init_but_t *but_data)
{
    sfFloatRect tmp = {but_data->x_coor, but_data->y_coor,
    but_data->rect_width, but_data->rect_height};

    button->rect = tmp;
    button->fct = but_data->fct;
    button->current_rect = 0;
    return (0);
}

void init_button_rect(button_t *button, const init_but_t *but_data)
{
    if (but_data->rect_tab != 0) {
        for (int i = 0; i < 3; i++) {
            button->rect_tab[i] = but_data->rect_tab[i];
        }
        sfSprite_setTextureRect(button->b_sprite.img, button->rect_tab[0]);
    }
}

int init_button(button_t *button, const init_but_t *but_data)
{
    const init_sprite_t sprite_data =
    {but_data->path, but_data->x_coor, but_data->y_coor};

    if (init_sprite(&button->b_sprite, &sprite_data) == -1)
        return (-1);
    init_button_rect(button, but_data);
    init_button_data(button, but_data);
    return (0);
}