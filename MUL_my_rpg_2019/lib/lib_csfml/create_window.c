/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** create_window
*/

#include "lib_csfml.h"

sfRenderWindow *create_window(sfVideoMode mode, char *title, sfUint32 style)
{
    sfRenderWindow *window = sfRenderWindow_create(mode, title, style, NULL);

    return (window);
}

sfVideoMode create_video_mode(int width, int height, int bits_per_pixel)
{
    sfVideoMode mode = {width, height, bits_per_pixel};

    return (mode);
}