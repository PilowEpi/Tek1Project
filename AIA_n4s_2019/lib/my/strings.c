/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** strings util
*/

#include <stdlib.h>

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int len = 0;

    for (; dest[len] != '\0'; len++);
    for (int i = 0; src[i] != '\0'; i++)
        dest[len + i] = src[i];
    return (dest);
}

int my_strcmp(const char *s1, const char *s2)
{
    for (int i = 0; s1[i] != '\0' || s2[i] != '\0'; i++){
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    return (0);
}

char *my_strcpy(char *dest, char const *str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++){
        dest[i] = str[i];
    }
    dest[i] = '\0';
    return dest;
}

char *my_strdup(char const *str)
{
    int len = my_strlen(str) + 1;
    char *copy = malloc(sizeof(char) * len);
    int i = 0;

    for (; str[i] != '\0'; i++)
        copy[i] = str[i];
    copy[i] = '\0';
    return (copy);
}

int my_strlen(char const *str)
{
    int counter = 0;
    for (; *str != '\0'; str++)
        counter++;
    return (counter);
}
