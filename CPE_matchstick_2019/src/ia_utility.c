/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** ia_utility
*/

#include "matchstick.h"
#include "my.h"

int is_odd(match_t *game)
{
    int line_at_null = 0;

    for (int i = 0; i < game->max_line; i++) {
        if (game->match_value[i] == 0)
            line_at_null++;
    }
    if ((game->max_line - line_at_null) % 2 == 0)
        return (0);
    return (1);
}

int get_max_matches(int *match_value, int max_stick, int line)
{
    if (match_value[line] < max_stick) {
        return (match_value[line]);
    } else {
        return (max_stick);
    }
}

int total_matches(match_t *game)
{
    int total_matches = 0;

    for (int i = 0; i < game->max_line; i++) {
        total_matches += game->match_value[i];
    }
    return (total_matches);
}

int get_greater_line(match_t *game)
{
    int greater_line = 0;

    for (int i = 0; i < game->max_line; i++) {
        if (game->match_value[greater_line] < game->match_value[i])
            greater_line = i;
    }
    return (greater_line);
}