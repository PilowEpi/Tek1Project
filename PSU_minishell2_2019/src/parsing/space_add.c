/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** space_add
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

int is_funct(char c)
{
    switch (c) {
        case '|':
            return (2);
        case '>':
        case '<':
            return (1);
        default:
            return (0);
    }
    return (0);
}

int is_space(char *str, int len)
{
    if ((is_funct(str[len]) == 2 && str[len + 1] !=  ' ') ||
        ((is_funct(str[len]) == 1 && str[len + 1] &&
        str[len + 1] !=  ' ' && is_funct(str[len + 1]) == 0)) ||
        (len != 0 && !is_funct(str[len]) && is_funct(str[len + 1]))) {
        return (1);
    }
    return (0);
}

int count_space(char *str)
{
    int count = 0;
    int quote = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        quote = in_quote(str, i);
        if (str[i] == ' ') {
            continue;
        } else if (!quote && is_space(str, i)) {
                count++;
        }
    }
    return (count);
}

int fill_with_space(char *new_str, char *str)
{
    int quote = 0;
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++, j++) {
        quote = in_quote(str, i);
        new_str[j] = str[i];
        if (str[i] == ' ') {
            continue;
        } else if (!quote && is_space(str, i)) {
            j++;
            new_str[j] = ' ';
        }
    }
    return (0);
}

char *space_add(char *str, int to_free)
{
    int len = my_strlen(str) + count_space(str) + 1;
    char *new_str = NULL;

    if (len == (my_strlen(str) + 1))
        return (str);
    new_str = malloc(sizeof(char) * len);
    if (new_str == NULL)
        return (NULL);
    my_memset(new_str, len);
    fill_with_space(new_str, str);
    if (to_free == 1)
        free(str);
    return (new_str);
}