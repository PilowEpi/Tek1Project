/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** initialize_window
*/

#include "my.h"
#include "defender.h"
#include "struct_defender.h"

void init_window(window_t *window, int heigth, int width)
{
    window->heigth = heigth;
    window->width = width;
    window->frame_limit = 60;
    window->scale_ratio = 1;
    window->win_size = (sfVector2u){1920, 1080};
}

int create_window(window_t *window)
{
    sfVideoMode video_mode;

    video_mode.height = window->heigth;
    video_mode.width = window->width;
    video_mode.bitsPerPixel = 32;
    window->window = sfRenderWindow_create(video_mode, "My_Defender",
                                            sfClose, NULL);
    if (!window->window) {
        my_printf("Win not created > Exit\n");
        return (84);
    }
    sfRenderWindow_setPosition(window->window, (sfVector2i){0, 0});
    sfRenderWindow_setFramerateLimit(window->window,
                                    window->frame_limit);
    return (0);
}

void initialize_window(window_t *win, int *returned)
{
    if (*returned == 84)
        return;
    init_window(win, 1080, 1920);
    if (create_window(win) == 84) {
        *returned = 84;
        return;
    }
}
