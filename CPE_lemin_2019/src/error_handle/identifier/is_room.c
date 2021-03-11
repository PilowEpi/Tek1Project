/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** is_room
*/

#include "my.h"
#include "lemin.h"

int check_space(char *line)
{
    int counter = 0;

    for (int i = 0; line[i]; i++) {
        if (line[i] == ' ') {
            counter++;
        }
    }
    return (counter);
}

int is_room(char *line)
{
    int len = 0;

    if (check_space(line) != 2)
        return (0);
    for (; line[len] && line[len] != ' '; len++);
    len++;
    for (; line[len] && line[len] != ' '; len++) {
        if (!is_num(line[len])) {
            return (84);
        }
    }
    len++;
    for (; line[len] && line[len] != ' '; len++) {
        if (!is_num(line[len])) {
            return (84);
        }
    }
    return (1);
}