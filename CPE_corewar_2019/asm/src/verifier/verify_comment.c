/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** verify_comment
*/

#include "my.h"
#include "corewar.h"
#include "op.h"

int verify_comment(file_t *head)
{
    if (my_strcmp(head->next->command, COMMENT_CMD_STRING)) {
        my_put_error("ASM : line ");
        print_line_error(head->next->line);
        my_put_error(": The comment must be just after the name.\n");
        return (84);
    } else if (!head->next->args ||
        (my_strlen(head->args[0]) >= PROG_NAME_LENGTH)) {
        my_put_error("ASM : line ");
        print_line_error(head->next->line);
        my_put_error(": Invalid Comment (No comment / Too long)\n");
        return (84);
    }
    return (0);
}