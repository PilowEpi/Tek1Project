/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_print_str
*/

#include "my.h"
#include <stdarg.h>
#include <stdlib.h>

void my_print_str(va_list *list)
{
    my_putstr(va_arg(*list, char *));
}

void get_octal_from(char c)
{
    my_putstr("\\");
    if (c < 8){
        my_putstr("00");
        my_put_octal(c);
    } else if (c < 64) {
        my_putchar('0');
        my_put_octal(c);
    } else {
        my_put_octal(c);
    }
}

void my_print_str_t(va_list *list)
{
    int i = 0;
    char *str = my_strdup(va_arg(*list, char *));

    while (str[i] != '\0') {
        if (str[i] < 32 && str[i] < 127) {
            get_octal_from(str[i]);
        } else {
            my_putchar(str[i]);
        }
        i++;
    }
    free(str);
}