/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** verify_args
*/

#include "my.h"
#include "op.h"
#include "corewar.h"

int is_correct_args(file_t *curr, int op)
{
    int curr_type = 0;
    int ok_type = 0;

    for (int i = 0; curr->args[i]; i++) {
        curr_type = get_type(curr->args[i]);
        if (curr_type == -2 || curr_type == -3 || curr_type == -1)
            return (84);
        else if (op_tab[op].type[i] & curr_type)
            ok_type++;
    }
    if (ok_type == op_tab[op].nbr_args)
        return (0);
    return (84);
}

int verify_args(file_t *curr)
{
    char *cmd = curr->command;

    for (int i = 0; op_tab[i].mnemonique; i++) {
        if (!my_strcmp(op_tab[i].mnemonique, cmd)) {
            return (is_correct_args(curr, i));
        }
    }
    return (0);
}