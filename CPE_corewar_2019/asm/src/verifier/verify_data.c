/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** verify_data
*/

#include <stddef.h>
#include <stdlib.h>

#include "my.h"
#include "op.h"
#include "corewar.h"

int verify_got_string(file_t *head, char *to_cmp)
{
    file_t *tmp = head;
    int count = 0;

    while (tmp != NULL) {
        if (!my_strcmp(tmp->command, to_cmp))
            count++;
        tmp = tmp->next;
    }
    if (count != 1)
        return (84);
    return (0);
}

int verify_command(file_t *curr)
{
    char *cmd = curr->command;
    char *basic_cmd[] = {NAME_CMD_STRING, COMMENT_CMD_STRING};

    if (!my_strcmp(basic_cmd[0], cmd) || !my_strcmp(basic_cmd[1], cmd))
        return (0);
    for (int i = 0; op_tab[i].mnemonique; i++) {
        if (!my_strcmp(op_tab[i].mnemonique, cmd))
            return (0);
    }
    if (is_label(cmd) == -1)
        return (0);
    my_put_error("ASM : line ");
    print_line_error(curr->line);
    my_put_error(": Invalid instruction.\n");
    return (84);
}

int verify_header(asm_t *asm_data)
{
    file_t *tmp = asm_data->command;

    while (tmp != NULL) {
        if (verify_command(tmp)) {
            return (84);
        } else if (verify_syntax(tmp) == 84 || verify_args(tmp)) {
            my_put_error("ASM : line ");
            print_line_error(tmp->line);
            my_put_error(": Invalid Syntax.\n");
            return (84);
        }
        tmp = tmp->next;
    }
    tmp = asm_data->command;
    if (verify_name_place(tmp) || verify_got_string(tmp, NAME_CMD_STRING) ||
        verify_got_string(tmp, COMMENT_CMD_STRING) || verify_comment(tmp))
        return (84);
    return (0);
}

int verify_data(asm_t *asm_data)
{
    if (verify_header(asm_data))
        return (1);
    return (0);
}