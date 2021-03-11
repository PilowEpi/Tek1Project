/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** Split a string into words
*/

#include <string.h>
#include <stdlib.h>
#include "sh.h"

char *mov_to_space(int x, char *src)
{
    char *dup = src;

    for (; dup && *dup; dup++) {
        if (!x)
            break;
        if (*dup == ' ')
            x--;
    }
    return (dup);
}

int needed_spaces(int x, char *str)
{
    char *dup = mov_to_space(x, str);
    int count = 0;

    for (; dup && *dup; count++, dup++)
        if (*dup == ' ')
            return (count);
    return (count);
}

void clean_str(char *src)
{
    int y = 0;
    int x = 0;

    for (char *cpy = src; cpy && *cpy; cpy++)
        if (*cpy == '\t')
            *cpy = ' ';
    for (; src[x] == ' '; x++);
    for (; src[x]; x++, y++){
        while (src[x] == ' ' && src[x + 1] == ' ')
            x++;
        src[y] = src[x];
    }
    src[y] = 0;
    for (y = strlen(src) - 1; y > 0; y--)
        if (src[y] == ' ')
            src[y] = 0;
        else
            break;
}

char **my_str_to_word_array(char *src)
{
    char **res;
    int size = 0;
    int space = 0;

    clean_str(src);
    for (char *cpy = src; cpy && *cpy; cpy++)
        if (*cpy == ' ')
            size++;
    res = malloc(sizeof(char *) * (size + 2));
    res ? res[size + 1] = 0 : exit(84);
    for (int x = 0; x < size + 1; x++) {
        space = needed_spaces(x, src);
        res[x] = malloc(space + 1);
        res[x] ? res[x][space] = 0 : exit(84);
        memcpy(res[x], mov_to_space(x, src), space);
    }
    decrypt_inibited(res);
    return (res);
}
