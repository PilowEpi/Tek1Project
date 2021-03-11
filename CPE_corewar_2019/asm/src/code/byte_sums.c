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

int calculate_function(file_t *curr, int *ptr)
{
    curr->size++;
    curr->byte_code[*ptr] = get_command_id(curr->command);
    *ptr = *ptr + 1;
    return (0);
}

int byte_sums(asm_t *asm_data)
{
    file_t *tmp = asm_data->command;
    int ptr = 0;

    tmp = tmp->next->next;
    while (tmp != NULL) {
        if (is_label(tmp->command) == -1) {
            tmp = tmp->next;
            continue;
        }
        calculate_function(tmp, &ptr);
        calculate_params(tmp, &ptr);
        calculate_args(tmp, &ptr);
        tmp->size = ptr;
        ptr = 0;
        tmp = tmp->next;
    }
    debug_task(asm_data->command);
    return (0);
}