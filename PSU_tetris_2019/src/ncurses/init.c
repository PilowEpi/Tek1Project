/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** game.c
*/

#include "tetris.h"
#include "my.h"
#include <stdlib.h>
#include <ncurses.h>

void init_map(game_t *game)
{
    game->map.fix = 1;
    game->map.x = game->data.map_size_x;
    game->map.y = game->data.map_size_y;
    game->info.x = 1;
    game->info.y = game->map.y / 2;
    game->map.map = malloc(sizeof(char *) * (game->map.x + 1));
    for (int i = 0; i < game->map.x; i++) {
        game->map.map[i] = malloc(sizeof(char) * game->map.y + 1);
        for (int j = 0; j < game->map.y; j++)
            game->map.map[i][j] = ' ';
    }
}

void init_ncurses(game_t *game)
{
    WINDOW *window = initscr();

    keypad(stdscr, true);
    noecho();
    cbreak();
    nodelay(window, TRUE);
    curs_set(0);
    start_color();
    attron(A_BOLD);
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_WHITE, COLOR_BLACK);
    init_map(game);
    init_score(game);
    init_nextform(game);
    init_tetris_game(game);
}

int draw_tetris(void)
{
    drawt(1, 0, 1);
    drawe(2, 6, 1);
    drawt(3, 12, 1);
    drawr(4, 18, 1);
    drawi(5, 24, 1);
    draws(6, 25, 1);
}

int games_ncurses(game_t *game)
{
    init_ncurses(game);
    int value = 0;
    int key = 0;

    while (1) {
        move(0, 0);
        draw_tetris();
        if (play_tetris(game) == 1)
            break;
        refresh_game(game);
    }
    attroff(A_BOLD);
    endwin();
    return (0);
}