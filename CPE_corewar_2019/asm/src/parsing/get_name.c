/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** get_name
*/

#include <stdlib.h>
#include "my.h"
#include "corewar.h"

char *get_only_name(char *name)
{
    int total_len = my_strlen(name);
    int len = 0;
    char cut = name[0];
    char *result = NULL;

    for (;name[total_len] != cut && name[total_len] != '/'; len++) {
        total_len--;
    }
    if (name[total_len] == '/')
        total_len++;
    result = malloc(len + 1);
    if (!result)
        return (NULL);
    result[len] = '\0';
    for (int i = 0; i < len; i++) {
        result[i] = name[total_len + i];
    }
    return (result);
}

char *get_name(char *filename)
{
    int len = 0;
    char *name = NULL;
    char *only_name = NULL;

    for (; filename[len] != '\0' && filename[len] != '.'; len++);
    name = malloc(len + 1);
    if (!name)
        return (NULL);
    name[len] = '\0';
    for (int i = 0; i < len; i++) {
        name[i] = filename[i];
    }
    only_name = get_only_name(name);
    free(name);
    return (only_name);
}