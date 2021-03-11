/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** is_indirect
*/

#include "my.h"

int is_indirect(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (i == 0 && str[i] == '-')
            continue;
        if (!is_num(str[i])) {
            return (-1);
        }
    }
    return (0);
}