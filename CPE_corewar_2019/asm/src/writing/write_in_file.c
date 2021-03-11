/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** write_in_file
*/

#include <stdio.h>
#include <unistd.h>

#include "op.h"
#include "my.h"
#include "corewar.h"

char **retrive_args(asm_t *asm_data, char *to_get)
{
    file_t *tmp = asm_data->command;

    if (!tmp)
        return (NULL);
    while (tmp && my_strcmp(tmp->command, to_get)) {
        tmp = tmp->next;
    }
    if (!tmp)
        return (NULL);
    return (tmp->args);
}

int write_name(int fd, asm_t *asm_data)
{
    char buf[PROG_NAME_LENGTH + 1];
    char **name = retrive_args(asm_data, NAME_CMD_STRING);
    int len = my_strlen(name[0]);

    for (int i = 0; i < PROG_NAME_LENGTH + 1; i++)
        buf[i] = '\0';
    for (int i = 0; i < (len - 2); i++)
        buf[i] = name[0][i + 1];
    write(fd, buf, PROG_NAME_LENGTH + 1);
    return (0);
}

int write_comment(int fd, asm_t *asm_data)
{
    char buf[COMMENT_LENGTH + 1];
    char **name = retrive_args(asm_data, COMMENT_CMD_STRING);
    int len = my_strlen(name[0]);

    for (int i = 0; i < COMMENT_LENGTH + 1; i++)
        buf[i] = '\0';
    for (int i = 0; i < (len - 2); i++)
        buf[i] = name[0][i + 1];
    write(fd, buf, COMMENT_LENGTH + 1);
    return (0);
}

int write_in_file(asm_t *asm_data, int fd)
{
    int magic = COREWAR_EXEC_MAGIC;
    int swapped = 0;

    for (int i = 0; i < 4; i++)
        swapped =  (swapped << 8) | (magic & 0xFF), magic >>= 8;;
    write(fd, &swapped, sizeof(swapped));
    write_name(fd, asm_data);
    write_comment(fd, asm_data);
    write_byte_code(fd, asm_data);
    return (0);
}