/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** init_game.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include "tetris.h"

void init_info(game_t *game)
{
    game->tetris_info.high_score = 0;
    game->tetris_info.score = 0;
    game->tetris_info.line = 0;
    game->tetris_info.is_paused = 0;
    game->tetris_info.level = 0;
}

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));
    if (!game)
        return (NULL);
    game->tetriminos = malloc(sizeof(char *) * 40);
    if (!game->tetriminos || init_list(game) == 1)
        return (NULL);
    game->scene.tetris = NULL;
    game->scene.score = NULL;
    game->scene.next_form = NULL;
    init_info(game);
    return (game);
}