/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** move_player
*/

#include "my.h"
#include "sokoban.h"
#include <ncurses.h>

void key_pressed(game_t *game, int ch)
{
    switch (ch) {
        case KEY_UP :
            generic_move(game, 0, -1);
            break;
        case KEY_DOWN :
            generic_move(game, 0, 1);
            break;
        case KEY_LEFT :
            generic_move(game, -1, 0);
            break;
        case KEY_RIGHT :
            generic_move(game, 1, 0);
            break;
        default:
            break;
    }
}

int move_player(game_t *game)
{
    int ch = getch();

    key_pressed(game, ch);
    if (ch == ' ')
        restart_game(game);
    else if (ch == KEY_BACKSPACE)
        game->condition = 2;
    return (0);
}