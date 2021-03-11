/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** print_line_error
*/

#include <stdlib.h>

#include "my.h"
#include "op.h"
#include "corewar.h"

void print_line_error(int line)
{
    char *nbr = my_stoi(line);

    my_put_error(nbr);
    free(nbr);
}