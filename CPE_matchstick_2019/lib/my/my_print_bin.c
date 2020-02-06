/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_print_bin
*/

#include "my.h"
#include <stdarg.h>

void my_print_bin(va_list *list)
{
    my_put_bin(va_arg(*list, unsigned int));
}