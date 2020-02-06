/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** ia_random
*/

#include <stdlib.h>

int ai_random(int *map, int map_size, int max_m)
{
    int line;
    int match;
    while (1) {
        line = rand() % map_size;
            if (map[line] > 0)
                break;
    }
    while (1) {
        match = rand() % max_m + 1;
        if (map[line] >= match)
            break;
    }
    map[line] -= match;
    return (0);
}