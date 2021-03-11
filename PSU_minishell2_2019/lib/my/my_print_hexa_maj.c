/*
** EPITECH PROJECT, 2019
** my_print_hexa_maj.c
** File description:
** my_print_hexa_maj
*/

#include "my.h"
#include <stdarg.h>

void my_print_hexa_maj(va_list *list)
{
    my_put_hexa_maj(va_arg(*list, unsigned int));
}