/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** is_reg
*/

#include "my.h"
#include "op.h"

int is_reg(char *str)
{
    int max_reg = REG_NUMBER;
    int result = 0;

    if (str[0] != 'r' && str[1] != '\0')
        return (-1);
    for (int i = 1; str[i]; i++) {
        if (i == 1 && str[i] == '-')
            continue;
        if (!is_num(str[i])) {
            my_put_error("Invalid Register Number\n");
            return (-3);
        }
    }
    result = my_getnbr(&str[1]);
    if (result > max_reg) {
        my_put_error("Register Too High\n");
        return (-2);
    }
    return (1);
}