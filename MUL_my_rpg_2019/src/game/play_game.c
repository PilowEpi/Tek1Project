/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** play_game
*/

#include "rpg.h"
#include "rpg_struct.h"
#include "rpg_dico.h"
#include "my.h"

void manage_clock(clocks_t *clock)
{
    clock->Time = sfClock_getElapsedTime(clock->clock);
    clock->seconds = clock->Time.microseconds / 100000.0;
}

int main_loop(glo_t *gl)
{
    manage_clock(&gl->main_clock);
    if (draw_scene(gl) == 84)
        return (84);
    return (0);
}

int play_game(glo_t *gl)
{
    while (sfRenderWindow_isOpen(gl->win.window)){
        sfRenderWindow_clear(gl->win.window, sfBlack);
        main_loop(gl);
        sfRenderWindow_display(gl->win.window);
    }
    return (0);
}
