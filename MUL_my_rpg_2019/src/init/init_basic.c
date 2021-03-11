/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_basic
*/

#include <stdlib.h>

#include "rpg.h"
#include "rpg_struct.h"
#include "my.h"
#include "lib_csfml.h"

int init_win(window_t *win)
{
    win->mode = create_video_mode(win->width, win->height, 32);
    win->window = create_window(win->mode, "My_Rpg", sfClose);
    if (!win->window) {
        my_printf("Win not created > Exit\n");
        return (84);
    }
    sfRenderWindow_setPosition(win->window, (sfVector2i){0, 0});
    sfRenderWindow_setFramerateLimit(win->window,
                                    win->frame_limit);
    return (0);
}

int init_data(glo_t *gl)
{
    gl->curr_scene = MENU;
    gl->win.frame_limit = 60;
    gl->win.width = 1920;
    gl->win.height = 1080;
    gl->win.win_size = (sfVector2u){1920, 1080};
    gl->scale_ratio = 1;
    gl->main_clock.clock = sfClock_create();
    gl->goal = 0;
    return (0);
}

int init_globals(glo_t *gl)
{
    init_data(gl);
    gl->data = malloc(sizeof(globals_t));
    init_main(gl->data);
    gl->data->data = gl;
    if (init_win(&gl->win))
        return (84);
    return (0);
}
