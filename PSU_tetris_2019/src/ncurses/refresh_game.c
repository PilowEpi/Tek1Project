/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** refresh_game
*/

#include "tetris.h"

int refresh_game(game_t *game)
{
    wrefresh(game->scene.score);
    wrefresh(game->scene.next_form);
    wrefresh(game->scene.tetris);
    refresh();
    return (0);
}