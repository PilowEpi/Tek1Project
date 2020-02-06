/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** create_map
*/

#include <stddef.h>
#include <stdlib.h>
#include "matchstick.h"
#include "my.h"

int *create_int_tab(int line)
{
    int *value_tab = malloc(sizeof(int) * line);
    int value = 1;

    if (value_tab == NULL)
        return (NULL);
    for (int i = 0; i < line; i++) {
        value_tab[i] = value;
        value += 2;
    }
    return (value_tab);
}

int create_map(match_t *game_value, int line)
{
    game_value->max_line = line;
    game_value->init_value = create_int_tab(line);
    game_value->match_value = create_int_tab(line);
    return (0);
}