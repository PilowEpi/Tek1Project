/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_print_ptr
*/

#include "my.h"
#include <stdarg.h>

void my_print_ptr(va_list *list)
{
    my_putstr("0x");
    my_put_hexa_ptr(va_arg(*list, long int));
}