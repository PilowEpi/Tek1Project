/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** byte_sums
*/

#include <stdlib.h>

#include "my.h"
#include "corewar.h"
#include "op.h"

int get_write(char *str, file_t *curr, int *ptr)
{
    if (!is_direct(str))
        return (write_direct(str, curr, ptr));
    if (!is_indirect(str))
        return (write_indirect(str, curr, ptr));
    if (is_index(str))
        return (write_index(str, curr, ptr));
    return (write_register(str, curr, ptr));
}

int calculate_args(file_t *curr, int *ptr)
{
    for (int i = 0; curr->args && curr->args[i]; i++) {
        get_write(curr->args[i], curr, ptr);
    }
    return (0);
}
