/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** set_params_key
*/

#include "my.h"
#include "tetris.h"

int set_error(char *argvs, options_t *data)
{
    return (84);
}

int set_level(char *argvs, options_t *data)
{
    for (int j = 0; argvs[j]; j++)
        if (!is_num(argvs[j]))
            return (84);
    data->start_level = my_getnbr(argvs);
    return (0);
}

int set_debug(char *argvs, options_t *data)
{
    data->debug_mode = 1;
    return (0);
}

int set_without(char *argvs, options_t *data)
{
    data->without_next = 1;
    return (0);
}

int set_mapsize(char *argvs, options_t *data)
{
    int i = 0;

    for (; argvs[i]; i++) {
        if (argvs[i] == '*')
            break;
    }
    if (i == my_strlen(argvs))
        return (84);
    for (int j = 0; argvs[j]; j++)
        if (!is_num(argvs[j]) && argvs[j] != '*')
            return (84);
    data->map_size_x = my_getnbr(argvs);
    data->map_size_y = my_getnbr(&argvs[i + 1]);
    return (0);
}