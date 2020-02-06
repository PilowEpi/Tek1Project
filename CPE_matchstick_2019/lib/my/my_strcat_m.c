/*
** EPITECH PROJECT, 2019
** my_strcat_m.c
** File description:
** my strcatmalloced
*/

#include "my.h"

char *my_strcat_m(char const *src1, char const *src2,
char *dest)
{
    int j = 0;

    for (int i = 0 ; src1[i] != '\0'; i++) {
        dest[j] = src1[i];
        j++;
    }
    for (int y = 0; src2[y] != '\0'; y++) {
        dest[j] = src2[y];
        j++;
    }
    return (dest);
}
