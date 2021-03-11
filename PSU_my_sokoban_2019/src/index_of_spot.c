/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** index_of_spot
*/

#include <ncurses.h>
#include "my.h"
#include "sokoban.h"

int index_of_spot(game_t *game, int x, int y)
{
    int index;

    for (int i = 0; i < game->count_spot; i++) {
        if ((game->spot_pos[i].x == x) && (game->spot_pos[i].y == y)) {
            index = i;
            game->spot_pos[i].is_visible = 0;
        }
    }
    return (index);
}