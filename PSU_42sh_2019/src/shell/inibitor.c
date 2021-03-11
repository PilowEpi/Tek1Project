/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** Inibitor of the shell
*/

#include <stdio.h>
#include <string.h>
#include "sh.h"

int change_spaces(char *str)
{
    int dq = 0;
    int sq = 0;

    for (char *line = str; *line; line++) {
        *line == '\\' ? line += 2 : 0;
        *line == '\'' & !dq ? sq++ : 0;
        *line == '\"' & !sq ? dq++ : 0;
        dq == 2 ? dq = 0 : 0;
        sq == 2 ? sq = 0 : 0;
        if (*line == ' ' & (dq | sq))
            *line = -2;
        if (*line == '\t' & (dq | sq))
            *line = -3;
    }
    if (sq | dq) {
        fprintf(stderr, "Unmatched '%c'.\n", sq ? '\'' : '\"');
        return (1);
    }
    return (0);
}

int try_to_change(char *c, int sq, int dq)
{
    int mov = 0;
    char from[] = "0abtnvfr\"\'\\$ \0";
    int const to[] = { -1, 7, 8, 9, 10, 11, 12, 13, -5, -6, -7, -8, -2};
    int const to_actors[] = {-10, -11, -12, -13, -14};
    char const actors[] = "&|<>;\0";

    if (*c == '\\') {
        c++;
        for (char *cpy = from; *cpy; cpy++, mov++)
            if (*c == *cpy) {
                *c = to[mov];
                return (1);
            }
    }
    for (int x = 0; (sq || dq) && actors[x]; x++)
        if (*c == actors[x]) {
            *c = to_actors[x];
            return (0);
        }
    return (0);
}

int translate_input(char *line)
{
    char *cpy = line;
    char const from[] = "0abtnvfr\"\'\\$ \0";
    int mov = 0;
    int sq = 0;
    int dq = 0;

    if (!line)
        return (1);
    for (; *cpy; cpy++, mov++) {
        *cpy == '\'' & !dq ? sq++ : 0;
        *cpy == '\"' & !sq ? dq++ : 0;
        dq == 2 ? dq = 0 : 0;
        sq == 2 ? sq = 0 : 0;
        if (try_to_change(cpy, dq, sq))
            mov++;
        *cpy = line[mov];
    }
    *cpy = 0;
    return (change_spaces(line));
}
