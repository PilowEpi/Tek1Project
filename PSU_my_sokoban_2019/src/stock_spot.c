/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** stock_spot
*/

#include "my.h"
#include "sokoban.h"
#include <stddef.h>
#include <stdlib.h>

int search_spot(char **map)
{
    int count = 0;
    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            count += (map[i][j] == 'O') ? 1 : 0;
        }
    }
    return (count);
}

int is_spot(game_t *game, int i, int j, int k)
{
    if (game->map[i][j] == 'O') {
        game->spot_pos[k].x = j;
        game->spot_pos[k].y = i;
        game->spot_pos[k].is_visible = 1;
        return (1);
    }
    return (0);
}

int stock_spot(game_t *game)
{
    int k = 0;
    game->count_spot = search_spot(game->map);

    game->spot_pos = malloc(sizeof(spot_t) * game->count_spot);
    if (game->spot_pos == NULL)
        return (84);
    for (int i = 0; game->map[i] != NULL; i++) {
        for (int j = 0; game->map[i][j] != '\0'; j++) {
            k += is_spot(game, i, j, k);
        }
    }
    return (0);
}