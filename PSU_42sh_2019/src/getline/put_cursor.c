/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** Put cursor
*/

#include <stdio.h>
#include "my.h"
#include "sh.h"

int put_cursor(int *cursor, lld_t *str)
{
    while (*cursor != 0) {
        *cursor = *cursor - 1;
        printf("\033[D");
    }
    return (6);
}
