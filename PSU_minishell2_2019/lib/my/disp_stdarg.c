/*
** EPITECH PROJECT, 2019
** disp_stdarg.c
** File description:
** display stdarg
*/

#include <stdarg.h>
#include "my.h"

int disp_stdarg(char *s, ...)
{
    va_list list;

    va_start(list, s);
    while (*s) {
        switch (*s++) {
        case 'c':
            my_putchar(va_arg(list, int));
            break;
        case 's':
            my_putstr(va_arg(list, char *));
            break;
        case 'i':
            my_put_nbr(va_arg(list, int));
            break;
        }
        my_putchar('\n');
    }
    va_end(list);
    return (0);
}
