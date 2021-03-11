/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** get_type
*/

#include "corewar.h"
#include "op.h"
#include "my.h"

int get_type(char *str)
{
    if (!is_direct(str))
        return (T_DIR);
    if (!is_indirect(str))
        return (T_IND);
    if (is_index(str))
        return (T_DIR);
    return (is_reg(str));
}