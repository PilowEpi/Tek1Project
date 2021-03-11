/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_print_unsi_int
*/

#include "my.h"
#include <stdarg.h>

void my_print_unsi_int(va_list *list)
{
    my_put_unsi_int(va_arg(*list, unsigned int));
}