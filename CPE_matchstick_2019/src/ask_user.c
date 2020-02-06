/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** ask_user
*/

#include <stddef.h>
#include <stdlib.h>
#include "matchstick.h"
#include "my.h"

int ask_matches(party_t *match, int line)
{
    char *input = NULL;
    int output = 0;

    my_printf("Matches: ");
    input = get_user_input();
    if (input == NULL)
        return (-2);
    while (verify_params(input) == -1 ||
            verify_matches(my_getnbr(input), line, match) != 0) {
                free(input);
                return (-1);
    }
    output = my_getnbr(input);
    free(input);
    return (output);
}

int ask_line(party_t *match)
{
    char *input = NULL;
    int output = 0;

    my_printf("Line: ");
    input = get_user_input();
    if (input == NULL)
        return (-2);
    while (verify_params(input) == -1 ||
            verify_line(my_getnbr(input), match->game.max_line) != 0) {
                free(input);
                my_printf("Line: ");
                input = get_user_input();
                if (input == NULL)
                    return (-2);
    }
    output = my_getnbr(input);
    free(input);
    return (output);
}

int ask_user(party_t *match)
{
    int line = 0;
    int matches = -1;

    my_printf("\nYour Turn:\n");
    while (matches == -1) {
        line = ask_line(match);
        if (line == -2)
            return (101);
        matches = ask_matches(match, line);
        if (matches == -2)
            return (101);
    }
    my_printf("Player removed %i match(es) from line %i\n", matches, line);
    match->game.match_value[line - 1] -= matches;
    return (0);
}
