/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** clean_memory
*/


#include <stdlib.h>

#include "my.h"
#include "corewar.h"
#include "op.h"

void free_data(file_t *data)
{
    file_t *tmp = data;
    file_t *to_free;

    while (tmp != NULL) {
        to_free = tmp;
        tmp = tmp->next;
        free(to_free->command);
        if (to_free->args) {
            free_my_str_array(to_free->args);
        }
        free(to_free);
    }
}

void clean_memory(asm_t *asm_data)
{
    free(asm_data->name);
    free_my_str_array(asm_data->base_file);
    free_data(asm_data->command);
}