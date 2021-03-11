/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** clock_module
*/

#include <time.h>
#include "tetris.h"

void get_time(game_t *game, int *second, int *minute)
{
    static clock_t time = 0;
    static clock_t elapsed = 0;
    clock_t current = 0;

    if (!game->tetris_info.is_paused) {
        current = clock() / CLOCKS_PER_SEC - elapsed;
        time = current;
    } else {
        elapsed = (clock() / CLOCKS_PER_SEC) - time;
    }
    *second = time % 60;
    *minute = time / 60;
}

int print_clock(game_t *game)
{
    int second = 0;
    int minute = 0;

    get_time(game, &second, &minute);
    mvwprintw(game->scene.score, 9, 27, "%2d : %2d", minute, second);
    return (0);
}