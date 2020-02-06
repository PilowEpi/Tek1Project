/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** print_map
*/

#include "matchstick.h"
#include "my.h"

void print_border(int value)
{
    for (int i = 0; i < value; i++)
        my_putchar('*');
    my_putchar('\n');
}

void print_line(match_t *game, int curr_line)
{
    int front_space = (game->init_value[game->max_line - 1] / 2) - curr_line;
    int back_space = (game->init_value[game->max_line - 1] / 2)- curr_line;
    int stick_off = game->init_value[curr_line] - game->match_value[curr_line];

    my_putchar('*');
    for (int  i = 0; i < front_space; i++)
        my_putchar(' ');
    for (int  i = 0; i < game->match_value[curr_line]; i++)
        my_putchar('|');
    for (int  i = 0; i < (back_space + stick_off); i++)
        my_putchar(' ');
    my_putstr("*\n");
}

void print_map(match_t *game)
{
    print_border((game->init_value[game->max_line - 1]) + 2);
    for (int i = 0; i < game->max_line; i++)
        print_line(game, i);
    print_border((game->init_value[game->max_line - 1]) + 2);
}