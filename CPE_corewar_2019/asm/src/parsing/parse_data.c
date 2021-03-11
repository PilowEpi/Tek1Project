/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** parse_data
*/

#include <stdlib.h>

#include "my.h"
#include "corewar.h"
#include "op.h"

int verify_space(char *str)
{
    int i = 0;
    int j = 0;

    if (str[0] == ' ' || str[0] == '\t') {
        for (;str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'); j++, i++);
        i = 0;
        for (;str[j] != '\0'; i++, j++) {
            str[i] = str[j];
        }
        str[i] = '\0';
    }
    return (0);
}

int remove_comment(char *to_check, int comment, int space, int count_spaces)
{
    if (comment - count_spaces == 0) {
        return (1);
    } else if (comment != -1 && space + 1 == comment) {
        for (int i = comment - count_spaces; to_check[i]; i++)
            to_check[i] = '\0';
    }
    return (0);
}

int verify_to_keep(char *to_check)
{
    int comment = -1;
    int count_spaces = 0;
    int space = -1;

    if (to_check[0] == '\0' || to_check[0] == COMMENT_CHAR)
        return (1);
    for (int i = 0; to_check[i] != '\0'; i++) {
        if (to_check[i] == ' ' || to_check[i] == '\t') {
            count_spaces++;
            space = i;
        } else if (to_check[i] == COMMENT_CHAR) {
            comment = i;
            break;
        } else {
            count_spaces = 0;
        }
    }
    return (remove_comment(to_check, comment, space, count_spaces));
}

int get_command(asm_t *asm_data)
{
    int line_counter = 1;

    for (int i = 0; asm_data->base_file[i]; i++, line_counter++) {
        if (verify_to_keep(asm_data->base_file[i]) ||
            verify_space(asm_data->base_file[i]))
            continue;
        else if (add_line_to_command(asm_data, i, &line_counter)) {
            return (1);
        }
    }
    return (0);
}

int parse_data(asm_t *asm_data)
{
    asm_data->command = NULL;
    if (get_command(asm_data))
        return (84);
    return (0);
}