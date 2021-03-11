/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** calculate_params
*/

#include <stdlib.h>

#include "my.h"
#include "corewar.h"
#include "op.h"

int bin_to_deci(char *str)
{
    int exp = 1;
    int result = 0;

    for (int i = 7; i >= 0; i--) {
        result += (exp * (str[i] - '0'));
        exp *= 2;
    }
    return (result);
}

char *get_code(char *str)
{
    if (!is_direct(str))
        return ("10");
    if (!is_indirect(str))
        return ("11");
    if (is_index(str))
        return ("10");
    return ("01");
}

int get_params_type(char **args)
{
    char bin[8];
    char *result = NULL;
    int j = 0;

    for (int k = 0; k < 8; k++)
        bin[k] = '0';
    for (int i = 0; args[i]; i++) {
        result = get_code(args[i]);
        bin[j] = result[0];
        j++;
        bin[j] = result[1];
        j++;
    }
    return (bin_to_deci(bin));
}

int need_prefix(char *str)
{
    int ban_id[] = {1, 9, 12, 15};
    int id = get_command_id(str);

    for (int i = 0; i < 4; i++) {
        if (id == ban_id[i])
            return (-1);
    }
    return (0);
}

int calculate_params(file_t *curr, int *ptr)
{
    if (need_prefix(curr->command) == -1)
        return (-1);
    curr->byte_code[*ptr] = get_params_type(curr->args);
    *ptr = *ptr + 1;
    return (0);
}
