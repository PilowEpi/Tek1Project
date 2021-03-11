/*
** EPITECH PROJECT, 2019
** my_print_hexa_min.c
** File description:
** my_print_hexa_min
*/

#include "my.h"
#include <stdarg.h>

void my_print_hexa_min(va_list *list)
{
    my_put_hexa_min(va_arg(*list, unsigned int));
}