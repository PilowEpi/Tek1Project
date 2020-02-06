/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** verify_input
*/

#include "my.h"
#include "matchstick.h"

int verify_matches(int matches, int line, party_t *match)
{
    int max = match->max_stick;
    if (matches > max) {
        my_printf("Error: you cannot remove more");
        my_printf(" than %i matches per turn\n", max);
        return (1);
    } else if (matches <= 0) {
        my_printf("Error: you have to remove at least one match\n");
        return (1);
    }
    if (match->game.match_value[line - 1] < matches) {
        my_printf("Error: not enough matches on this line\n");
        return (1);
    }
    return (0);
}

int verify_line(int line, int max_line)
{
    if (line > max_line || line <= 0) {
        my_printf("Error: this line is out of range\n");
        return (1);
    }
    return (0);
}

int verify_params(char *input)
{
    for (int i = 0; i < my_strlen(input) - 1; i++) {
        if (is_num(input[i]) == 0) {
            my_printf("Error: invalid input (positive number expected)\n");
            return (-1);
        }
    }
    return (0);
}