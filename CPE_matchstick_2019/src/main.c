/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** main
*/

#include <stdlib.h>
#include "my.h"
#include "matchstick.h"

void free_my_party(party_t *match)
{
    free(match->game.init_value);
    free(match->game.match_value);
}

int init_matchstick(party_t *match, int max_line, int max_move)
{
    match->max_stick = max_move;
    match->cur_player = USER;
    match->game_state = RUN;
    create_map(&match->game, max_line);
    return (0);
}

int matchstick(int max_line, int max_move)
{
    party_t match;

    init_matchstick(&match, max_line, max_move);
    if (launch_match(&match) == 84)
        return (0);
    free_my_party(&match);
    return (match.vict_return);
}

int error_management(char **av)
{
    if (verify_params(av[1]) == -1 || verify_params(av[2]) == -1) {
        return (84);
    }
    if (av[1][0] == '-' || av[2][0] == '-') {
        my_printf("Bad Input : Negative Number  > Exit \n");
        return (84);
    }
    if (my_atoi(av[1]) >= 100 || my_atoi(av[1]) <= 1) {
        my_printf("Bad Input : Bad number of Line  > Exit \n");
        return (84);
    }
    return (0);
}

int main(int ac, char **av)
{
    int max_line = 0;
    int max_move = 0;

    if (ac != 3) {
        return (84);
    } else if (error_management(av) == 84) {
        return (84);
    } else {
        max_line = my_atoi(av[1]);
        max_move = my_atoi(av[2]);
        return (matchstick(max_line, max_move));
    }
}