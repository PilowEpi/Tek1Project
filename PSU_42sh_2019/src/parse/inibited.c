/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** Inibited descriptor
*/

#include <string.h>
#include <stdio.h>

#include "sh.h"

void rm_quotes(char *str)
{
    int size = strlen(str);

    for (int x = 1; x < size - 1; x++)
        str[x - 1] = str[x];
    str[size - 2] = 0;
}

void decrypt_inibitor(char *c)
{
    int const from[] = { -1, -5, -6, -7, -8, -2, -3, 0};
    int const from_actors[] = {-10, -11, -12, -13, -14};
    char const to[] = "0\"\'\\$ \t\0";
    char const to_actors[] = "&|<>;\0";

    for (int x = 0; x < 7; x++)
        if (*c == from[x])
            *c = to[x];
    for (int x = 0; x < 5; x++)
        if (*c == from_actors[x])
            *c = to_actors[x];
}

void decrypt_inibited(char **array)
{
    for (int x = 0; array && array[x]; x++) {
        if (array[x][0] == '\'' || array[x][0] == '\"')
            rm_quotes(array[x]);
        for (int y = 0; array[x][y]; y++)
            decrypt_inibitor(&(array[x][y]));
    }
}

void luis_decrypt(char *str)
{
    for (int x = 0; str[x]; x++)
        decrypt_inibitor(&(str[x]));
}
