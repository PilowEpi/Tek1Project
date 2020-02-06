/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** game_loop
*/

#include "matchstick.h"
#include "my.h"

int is_end(party_t *match)
{
    for (int i = 0; i < match->game.max_line; i++) {
        if (match->game.match_value[i] != 0)
            return (1);
    }
    match->game_state = END;
    if (match->cur_player == USER)
        match->vict_return = 1;
    else if (match->cur_player == IA)
        match->vict_return = 2;
    return (0);
}

int choose_player(party_t *match)
{
    if (match->cur_player == USER) {
        if (ask_user(match) == 101)
            return (84);
        match->cur_player = IA;
    } else if (match->cur_player == IA) {
        my_printf("\nAI's turn...\n");
        ia_play(match);
        match->cur_player = USER;
    }
    return (0);
}

int launch_match(party_t *match)
{
    while (match->game_state != END) {
        print_map(&match->game);
        if (choose_player(match) == 84)
            return (84);
        is_end(match);
    }
    print_map(&match->game);
    if (match->cur_player == IA) {
        my_printf("You lost, too bad...\n");
    } else if (match->cur_player == USER) {
        my_printf("I lost... snif... but I'll get you next time!!\n");
    }
    return (0);
}