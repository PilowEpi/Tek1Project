/*
** EPITECH PROJECT, 2019
** my_strdup.c
** File description:
** task01
*/

#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *dest;
    int i = 0;
    int s = 0;

    while (src[s] != '\0')
        s++;
    dest = malloc(sizeof(char) * (s + 1));
    if (dest == 0)
        return (0);
    dest[s] = '\0';
    while (i < s) {
        dest[i] = src[i];
        i++;
    }
    return (dest);
}
