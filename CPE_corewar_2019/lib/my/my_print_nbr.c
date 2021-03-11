/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_print_nbr
*/

#include "my.h"
#include <stdarg.h>

void my_print_octal(va_list *list)
{
    my_put_octal(va_arg(*list, int));
}

void my_print_nbr(va_list *list)
{
    my_put_nbr(va_arg(*list, int));
}