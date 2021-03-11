/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** condition_game
*/

#include "my.h"
#include "sokoban.h"
#include <stddef.h>

int winning_condition(game_t *game)
{
    int count = 0;

    for (int i = 0; i < game->count_spot; i++) {
        if ((game->spot_pos[i].is_visible == 0) &&
            (game->map[game->spot_pos[i].y][game->spot_pos[i].x]) == 'X') {
                count++;
            }
    }
    if (count == game->count_spot)
        return (1);
    return (0);
}

int check_blocked(game_t *game, int y, int x)
{
    int x_axe = 0;
    int y_axe = 0;

    if (game->map[y][x] == 'X') {
        y_axe += (game->map[y + 1][x] == '#') ? 1 : 0;
        y_axe += (game->map[y - 1][x] == '#') ? 1 : 0;
        x_axe += (game->map[y][x + 1] == '#') ? 1 : 0;
        x_axe += (game->map[y][x - 1] == '#') ? 1 : 0;
    } else {
        return (0);
    }
    if ((x_axe >= 1) && (y_axe >= 1)) {
        return (1);
    }
    return (0);
}

int losing_condition(game_t *game)
{
    int count = 0;

    for (int i = 1; (game->map[i] != NULL); i++) {
        for (int j = 1; (game->map[i][j] != '\0'); j++) {
            count += (check_blocked(game, i, j) == 1) ? 1 : 0;
        }
    }
    if (count == game->count_spot)
        return (1);
    return (0);
}

int verify_condition(game_t *game)
{
    if (winning_condition(game) == 1) {
        game->condition = 0;
    } else if (losing_condition(game) == 1) {
        game->condition = 1;
    }
    return (0);
}