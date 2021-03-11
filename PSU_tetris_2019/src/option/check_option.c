/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** check_option
*/

#include <ncurses.h>
#include "tetris.h"
#include "my.h"

void init_data(options_t *data)
{
    data->debug_mode = 0;
    data->key_drop = KEY_DOWN;
    data->key_left = KEY_LEFT;
    data->key_right = KEY_RIGHT;
    data->key_quit = 'q';
    data->key_turn = KEY_UP;
    data->map_size_x = 20;
    data->key_pause = ' ';
    data->start_level = 1;
    data->map_size_y = 10;
    data->without_next = 0;
}

int check_same_data(int i, int j, options_t *data)
{
    int tab[] = {data->key_turn, data->key_right, data->key_quit,
        data->key_drop, data->key_left, data->key_pause};

    if (i != j && tab[i] == tab[j])
        return (1);
    return (0);
}

int check_data(options_t *data)
{
    int error = 0;

    for (int i = 0; i != 6; i++) {
        for (int j = 0; j != 6; j++) {
            error += check_same_data(i, j, data);
        }
    }
    if (error != 0) {
        my_printf("Error : Same input detected\n");
        return (84);
    }
    return (0);
}