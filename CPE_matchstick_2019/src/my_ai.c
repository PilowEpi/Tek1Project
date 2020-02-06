/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** my_ai
*/

#include "matchstick.h"
#include "my.h"

int my_ia(party_t *match)
{
    int tmp = 0;

    if (is_odd(&match->game) == 1) {
        tmp = get_max_matches(match->game.match_value,
                            match->max_stick, get_greater_line(&match->game));
        my_printf("AI removed %i match(es) from line %i\n", tmp - 1,
                get_greater_line(&match->game) + 1);
        match->game.match_value[get_greater_line(&match->game)] -= tmp - 1;
    } else {
        tmp = get_max_matches(match->game.match_value,
                            match->max_stick, get_greater_line(&match->game));
        my_printf("AI removed %i match(es) from line %i\n", tmp,
                get_greater_line(&match->game) + 1);
        match->game.match_value[get_greater_line(&match->game)] -= tmp;
    }
    return (0);
}

int ia_play(party_t *match)
{
    if (total_matches(&match->game) == 3 ||
        total_matches(&match->game) == 1) {
        my_printf("AI removed %i match(es) from line %i\n", 1,
                get_greater_line(&match->game) + 1);
        match->game.match_value[get_greater_line(&match->game)] -= 1;
    } else {
        my_ia(match);
    }
    return (0);
}