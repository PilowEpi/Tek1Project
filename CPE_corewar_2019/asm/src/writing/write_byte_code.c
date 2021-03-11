/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** write_byte_code
*/

#include <stdio.h>
#include <unistd.h>

#include "op.h"
#include "my.h"
#include "corewar.h"

int write_byte_code(int fd, asm_t *asm_data)
{
    file_t *tmp = asm_data->command;

    while (tmp) {
        if (tmp->size)
            write(fd, tmp->byte_code, tmp->size);
        tmp = tmp->next;
    }
    return (0);
}