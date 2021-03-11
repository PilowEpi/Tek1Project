/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** start_sokoban
*/

#include <ncurses.h>
#include "sokoban.h"
#include "my.h"
#include <stdlib.h>

void verify_spot_visible(game_t *game)
{
    for (int i = 0; i < game->count_spot; i++) {
        if ((game->spot_pos[i].is_visible == 0) &&
            (game->map[game->spot_pos[i].y][game->spot_pos[i].x]) == ' ') {
                game->spot_pos[i].is_visible = 1;
                game->map[game->spot_pos[i].y][game->spot_pos[i].x] = 'O';
            }
    }
}

int started_game(game_t *game)
{
    initscr();
    raw();
    keypad(stdscr, true);
    noecho();
    while (game->condition != 0 && game->condition != 1 &&
            game->condition != 2) {
        erase();
        verify_spot_visible(game);
        printw_my_array(game->map);
        find_player(game);
        move_player(game);
        verify_condition(game);
        refresh();
    }
    erase();
    printw_my_array(game->map);
    refresh();
    endwin();
    return (0);
}

int restart_game(game_t *game)
{
    free_my_str_array(game->map);
    game->map = my_str_to_word_array(game->reset);
    find_player(game);

    return (0);
}

int start_game(char *map)
{
    game_t game;

    game.p.x = 0;
    game.p.y = 0;
    game.map = my_str_to_word_array(map);
    game.reset = my_strdup(map);
    game.condition = 3;

    find_player(&game);
    stock_spot(&game);
    started_game(&game);
    free_my_str_array(game.map);
    free(game.reset);
    free(game.spot_pos);

    if (game.condition == 2)
        return (1);
    return (game.condition);
}