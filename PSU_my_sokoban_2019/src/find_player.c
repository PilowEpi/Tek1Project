/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** find_player
*/

#include "my.h"
#include "sokoban.h"
#include <stddef.h>

void find_player(game_t *game)
{
    int j = 0;

    for (int i = 0; game->map[i] != NULL; i++) {
        for (j = 0; (game->map[i][j] != '\0') &&
            (game->map[i][j] != 'P'); j++) {
        }
        if (game->map[i][j] == 'P') {
            game->p.x = j;
            game->p.y = i;
        }
    }
}