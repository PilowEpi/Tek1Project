/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** is_command
*/

#include "my.h"
#include "lemin.h"

int check_basic_command(char *line)
{
    if (line[0] != '#' && line[1] != '#')
        return (1);
    return (0);
}

int is_command(char *line)
{
    if (check_basic_command(line))
        return (0);
    else if (my_strcmp("##start", line) ||
        my_strcmp("##end", line))
        return (1);
    return (2);
}