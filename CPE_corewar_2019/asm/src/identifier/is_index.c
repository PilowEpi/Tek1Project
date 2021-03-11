/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** is_index
*/

#include "op.h"
#include "corewar.h"

int is_index(char *str)
{
    if (str[0] != DIRECT_CHAR || str[1] != LABEL_CHAR)
        return (0);
    for (int i = 2; str[i]; i++) {
        if (!is_label_char(str[i]))
            return (0);
    }
    return (1);
}