/*
** EPITECH PROJECT, 2019
** sum_stdarg.c
** File description:
** sum of arg
*/

#include <stdarg.h>
#include "my.h"

int sum_stdarg (int i, int nb, ...)
{
    va_list list;
    int count = 0;

    va_start(list, nb);
    switch (i) {
    case 0:
        for (int j = 0; j < nb; j++)
            count += va_arg(list, int);
        break;
    case 1:
        for (int k = 0; k < nb; k++)
            count += my_strlen(va_arg(list, char *));
        break;
    default :
        my_putstr("syntax error\n");
        return (84);
    }
    va_end(list);
    return (count);
}
