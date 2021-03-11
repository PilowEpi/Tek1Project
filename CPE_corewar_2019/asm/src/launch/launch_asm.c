/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** launch_asm
*/

#include <stdlib.h>

#include "my.h"
#include "corewar.h"
#include "op.h"

int set_data(asm_t *asm_data)
{
    if (verify_constant() || parse_data(asm_data) ||
        verify_data(asm_data) || byte_sums(asm_data) ||
        create_comp_file(asm_data)) {
        return (84);
    }
    return (0);
}

int get_data_from_file(asm_t *asm_data, char *filename)
{
    asm_data->name = get_name(filename);
    asm_data->base_file = open_file(filename);

    if (!asm_data->base_file ||
        asm_data->base_file[0][0] == '\0') {
        return (84);
    } else if (set_data(asm_data)) {
        return (84);
    }
    return (0);
}

int launch_asm(char *filename)
{
    asm_t asm_data;

    if (get_data_from_file(&asm_data, filename)) {
        return (84);
    }
    clean_memory(&asm_data);
    return (0);
}