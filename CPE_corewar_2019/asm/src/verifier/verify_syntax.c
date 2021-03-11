/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** verify_syntax
*/

#include "my.h"
#include "corewar.h"
#include "op.h"

int verify_syntax(file_t *curr)
{
    char *cmd = curr->command;
    int nbr = 0;

    for (;curr->args && curr->args[nbr]; nbr++);
    for (int i = 0; op_tab[i].mnemonique; i++) {
        if (!my_strcmp(op_tab[i].mnemonique, cmd)) {
            return ((nbr == op_tab[i].nbr_args) ? 0 : 84);
        }
    }
    return (0);
}