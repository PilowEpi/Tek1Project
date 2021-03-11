/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** set_basic_key
*/

#include "tetris.h"
#include "my.h"
#include <stdlib.h>

void fill_tab(int i, int *e, block_t *block, int j)
{
    int a = 0;

    for (int z = i + 1; z < block->y; z++)
        if (block->form[z][j] != 0 && block->form[z][j] != ' ')
            a = 1;
    if (a == 0 || i == block->y - 1) {
        block->collision[*e] = malloc(sizeof(int) * 2);
        block->collision[*e][0] = i;
        block->collision[(*e)++][1] = j;
    }
}

int set_key_right(char *argvs, options_t *data)
{
    if (my_strlen(argvs) == 1) {
        data->key_right = argvs[0];
    } else {
        my_printf("BAD INPUT\n");
        return (84);
    }
    return (0);
}

int set_key_turns(char *argvs, options_t *data)
{
    if (my_strlen(argvs) == 1) {
        data->key_turn = argvs[0];
    } else {
        my_printf("BAD INPUT\n");
        return (84);
    }
    return (0);
}

int set_key_left(char *argvs, options_t *data)
{
    if (my_strlen(argvs) == 1) {
        data->key_left = argvs[0];
    } else {
        my_printf("BAD INPUT\n");
        return (84);
    }
    return (0);
}

int set_key_drop(char *argvs, options_t *data)
{
    if (my_strlen(argvs) == 1) {
        data->key_drop = argvs[0];
    } else {
        my_printf("BAD INPUT\n");
        return (84);
    }
    return (0);
}