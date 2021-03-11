/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** is_direct
*/

#include "op.h"
#include "my.h"

int is_direct(char *str)
{
    if (str[0] != DIRECT_CHAR)
        return (-1);
    for (int i = 1; str[i] != '\0'; i++) {
        if (i == 1 && str[i] == '-')
            continue;
        if (!is_num(str[i]))
            return (-1);
    }
    return (0);
}