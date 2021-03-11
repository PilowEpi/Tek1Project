/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** play_game
*/

#include "struct_defender.h"
#include "defender.h"
#include "my.h"

void manage_clock(game_t *game)
{
    game->Time = sfClock_getElapsedTime(game->clock);
    game->seconds = game->Time.microseconds / 100000.0;
}

int play_game(window_t *win, game_t *game)
{
    sfMusic_play(game->ambiance);
    while (sfRenderWindow_isOpen(win->window)) {
        sfRenderWindow_clear(win->window, sfColor_fromRGB(105, 105, 105));
        manage_clock(game);
        if (draw_game(win, game) == 84)
            return (84);
        sfRenderWindow_display(win->window);
    }
    return (0);
}