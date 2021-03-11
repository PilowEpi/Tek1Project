/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** get_command_id
*/

#include "my.h"
#include "op.h"
#include "corewar.h"

int get_command_id(char *str)
{
    for (int i = 0; op_tab[i].mnemonique; i++) {
        if (!my_strcmp(op_tab[i].mnemonique, str)) {
            return (op_tab[i].code);
        }
    }
    return (-1);
}