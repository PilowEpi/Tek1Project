/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** write_type
*/

#include <stdlib.h>

#include "my.h"
#include "corewar.h"
#include "op.h"

int write_register(char *str, file_t *curr, int *ptr)
{
    int to_write = my_getnbr(&str[1]);

    curr->byte_code[*ptr] = to_write;
    *ptr = *ptr + 1;
    return (0);
}

int write_direct(char *str, file_t *curr, int *ptr)
{
    return (0);
}

int write_indirect(char *str, file_t *curr, int *ptr)
{
    return (0);
}

int write_index(char *str, file_t *curr, int *ptr)
{
    return (0);
}