/*
** EPITECH PROJECT, 2019
** my_printf.c
** File description:
** my_printf
*/

#include <stdarg.h>
#include "my.h"

int search_my_index(char check)
{
    int i = 0;

    for (i = 0; (check != tab[i].name) && (tab[i].name != 'E'); i++);
    return (i);
}

int my_printf(char const *str, ...)
{
    va_list list;
    int j = 0;
    int length_flags = 0;
    int count = 0;

    va_start(list, *str);
    for (int i = 0; str[i] != '\0'; i++, length_flags = 0) {
        if ((str[i] == '%') && (str[i + 1] != '\0') &&
            (search_my_index(str[i + 1]) < 12)) {
            length_flags += 1;
            j = search_my_index(str[i + 1]);
            tab[j].fct_ptr(&list);
            i += length_flags;
        } else {
            my_putchar(str[i]);
            count++;
        }
    }
    va_end(list);
    return (count);
}