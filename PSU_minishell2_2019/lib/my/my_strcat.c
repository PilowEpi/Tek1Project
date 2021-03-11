/*
** EPITECH PROJECT, 2019
** my_strcat.c
** File description:
** for lib
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int destl = my_strlen(dest);
    int i;

    for (i = 0 ; src[i] != '\0' ; i++)
        dest[destl + i] = src[i];
    dest[destl + i] = '\0';
    return (dest);
}
