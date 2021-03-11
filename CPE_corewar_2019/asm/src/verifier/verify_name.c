/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** verify_name
*/

#include "op.h"
#include "corewar.h"
#include "my.h"

int verify_name_place(file_t *head)
{
    if (my_strcmp(head->command, NAME_CMD_STRING)) {
        my_put_error("ASM : line ");
        print_line_error(head->line);
        my_put_error(": The name of your program must be the first line.\n");
        return (84);
    } else if (!head->args || (my_strlen(head->args[0]) >= COMMENT_LENGTH)) {
        my_put_error("ASM : line ");
        print_line_error(head->line);
        my_put_error(": Invalid Name (No comment / Too long)\n");
        return (84);
    }
    return (0);
}