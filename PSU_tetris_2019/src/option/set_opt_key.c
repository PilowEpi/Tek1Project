/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** set_opt_key
*/

#include "my.h"
#include "tetris.h"

int set_key_pause(char *argvs, options_t *data)
{
    if (my_strlen(argvs) == 1) {
        data->key_pause = argvs[0];
    } else {
        my_printf("BAD INPUT\n");
        return (84);
    }
    return (0);
}

int set_key_quit(char *argvs, options_t *data)
{
    if (my_strlen(argvs) == 1) {
        data->key_quit = argvs[0];
    } else {
        my_printf("BAD INPUT\n");
        return (84);
    }
    return (0);
}