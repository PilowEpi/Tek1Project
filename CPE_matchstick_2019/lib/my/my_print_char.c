/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_print_char
*/

#include <stdarg.h>
#include "my.h"

void my_print_char(va_list *list)
{
    my_putchar(va_arg(*list, int));
}