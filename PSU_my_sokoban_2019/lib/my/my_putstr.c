/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** for lib
*/

#include "my.h"
#include <unistd.h>

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}
