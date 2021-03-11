/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** is_pipe
*/

#include "my.h"
#include "lemin.h"

int is_pipe(char *line)
{
    int counter = 0;

    for (int i = 0; line[i]; i++) {
        if (line[i] == ' ')
            return (0);
        else if (line[i] == '-')
            counter++;
    }
    if (counter == 1)
        return (1);
    return (0);
}