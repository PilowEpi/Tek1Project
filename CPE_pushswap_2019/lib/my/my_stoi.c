/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_stoi
*/
#include <stdlib.h>

char *my_stoi(int nb)
{
    char *str;
    str = malloc(sizeof(int));
    int tmp;
    int length = 0;
    int n = nb;

    while (n != 0) {
        length++;
        n = n / 10;
    }
    for (int i = 0; i < length; i++) {
        tmp = nb % 10;
        nb = nb  / 10;
        str[length - (i + 1)] = tmp + '0';
    }
    str[length] = '\0';
    return (str);
}