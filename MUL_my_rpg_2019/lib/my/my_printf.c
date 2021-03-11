/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** primary file
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "my.h"

void pf_putchar(char c)
{
    write(1, &c, 1);
    char_printed += 1;
}

void pf_putstr(char const *s)
{
    int len = my_strlen(s);

    write(1, s, len);
    char_printed += len;
}

void print_arg(char const *format, int *i, va_list *ap)
{
    int ty = get_type(format, *i);
    long long conf = get_configuration(format, *i, *ap);

    *i = get_length_index(format, *i) + 1;
    if (ty < 0)
        return;
    pr[ty](ap, conf);
}

int check_format(char const *format, int *i, va_list *ap)
{
    if (format[*i] == '%' && format[*i] != '\0'){
        *i += 1;
        print_arg(format, i, ap);
        check_format(format, i, ap);
        return (1);
    }
    return (0);
}

int my_printf(const char *format, ...)
{
    va_list ap;

    char_printed = 0;
    va_start(ap, format);
    for (int i = 0; format[i] != '\0'; i++){
        if (check_format(format, &i, &ap)){
            i--;
            continue;
        }
        pf_putchar(format[i]);
    }
    va_end(ap);
    return (char_printed);
}
