/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** delete_line
*/

#include <stdlib.h>
#include "tetris.h"
#include "my.h"

char *create_corect_line(game_t *game)
{
    int length = game->data.map_size_x - 1;
    char *new_line = malloc(length + 1);

    new_line[length] = '\0';
    for (int i = 0; i < length; i++)
        new_line[i] = ' ';
    return (new_line);
}

int delete_line(game_t *game, int line)
{
    char *new_line = create_corect_line(game);

    for (int i = line; i >= 1; i--)
        for (int j = 0; j < game->map.y - 1; j++)
            game->map.map[i][j] = game->map.map[i - 1][j];
    for (int j = 0; j < game->map.y - 1; j++)
        game->map.map[0][j] = new_line[j];
    draw_game(game);
    wrefresh(game->scene.tetris);
    return (0);
}

int verify_line(game_t *game)
{
    int count = 0;
    int length = game->data.map_size_y - 1;

    for (int i = 1; i < game->map.x - 1; i++) {
        for (count = 1; count < game->map.y - 1 &&
            game->map.map[i][count] == '*'; count++);
        if (count == length)
            delete_line(game, i);
    }
    return (0);
}