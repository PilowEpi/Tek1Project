/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** init_subwin.c
*/

#include "tetris.h"
#include "my.h"
#include <stdlib.h>
#include <ncurses.h>

void init_score(game_t *game)
{
    game->scene.score = subwin(stdscr, LINES / 4, COLS / 5, 10, 2);
    box(game->scene.score, ACS_VLINE, ACS_HLINE);
    wborder(game->scene.score, '|', '|', '-', '-', '+', '+', '+', '+');
    wattron(game->scene.score, A_STANDOUT);
    mvwprintw(game->scene.score, 1, 16, "LEADERBOARD");
    wattroff(game->scene.score, A_STANDOUT);
    mvwprintw(game->scene.score, 3, 3, "High Score");
    mvwprintw(game->scene.score, 4, 3, "Actual Score");
    mvwprintw(game->scene.score, 6, 3, "Lines");
    mvwprintw(game->scene.score, 7, 3, "Levels");
    mvwprintw(game->scene.score, 9, 3, "Timer");
    wrefresh(game->scene.score);
    refresh();
}

void init_nextform(game_t *game)
{
    game->scene.next_form = subwin(stdscr, LINES / 8 + 1,
        COLS / 8, 1, game->map.y + 60);
    box(game->scene.next_form, ACS_VLINE, ACS_HLINE);
    wborder(game->scene.next_form, '|', '|', '-', '-', '+', '+', '+', '+');
    wattron(game->scene.next_form, A_ITALIC);
    mvwprintw(game->scene.next_form, 1, 2, "Next form:");
    wattroff(game->scene.next_form, A_ITALIC);
    wrefresh(game->scene.next_form);
    refresh();
}

void init_tetris_game(game_t *game)
{
    game->scene.tetris = subwin(stdscr, game->map.x, game->map.y, 1, 50);
    box(game->scene.tetris, ACS_VLINE, ACS_HLINE);
    wborder(game->scene.tetris, '|', '|', '<', '>', '+', '+', '+', '+');
    wrefresh(game->scene.tetris);
    refresh();
}