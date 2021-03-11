/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** create_text
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "struct_defender.h"
#include "defender.h"

int init_text(text_t *text, const init_text_t *text_data)
{
    sfVector2f vect = {text_data->x_coor, text_data->y_coor};
    sfColor color = sfColor_fromRGB(text_data->red_c,
                                    text_data->green_c, text_data->blue_c);

    text->pos = vect;
    text->font = sfFont_createFromFile(text_data->font);
    if (text->font == NULL)
        return (84);
    text->text = sfText_create();
    if (text->text == NULL)
        return (84);
    sfText_setString(text->text, text_data->text);
    sfText_setFont(text->text, text->font);
    sfText_setCharacterSize(text->text, text_data->size);
    sfText_setColor(text->text, color);
    return (0);
}