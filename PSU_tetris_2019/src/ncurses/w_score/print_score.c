/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** print_score
*/

#include "tetris.h"

void print_score(game_t *game)
{
    mvwprintw(game->scene.score, 3, 30, "%d",
        game->tetris_info.high_score);
    mvwprintw(game->scene.score, 4, 30, "%d",
        game->tetris_info.score);
    mvwprintw(game->scene.score, 6, 30, "%d",
        game->tetris_info.line);
    mvwprintw(game->scene.score, 7, 30, "%d",
        game->tetris_info.level);
}