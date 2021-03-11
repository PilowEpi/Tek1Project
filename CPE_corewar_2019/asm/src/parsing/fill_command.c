/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** fill_command
*/

#include <stdlib.h>

#include "my.h"
#include "corewar.h"
#include "op.h"

void debug_task(file_t *task)
{
    file_t *tmp = task;
    int i = 0;

    while (tmp != NULL) {
        my_printf("=====NODE [%d] =====\n", i);
        my_printf(" prev => %d\n", tmp->prev);
        my_printf(" next => %d\n", tmp->next);
        my_printf(" node adress => %d\n", tmp);
        my_printf(" line => %d\n", tmp->line);
        my_printf(" node command = %s\n", tmp->command);
        if (tmp->args)
            for (int j = 0; tmp->args[j]; j++)
                my_printf("node arg[%d] => %s\n", j, tmp->args[j]);
        my_printf(" size = %d\n", tmp->size);
        my_printf(" byte_code = [%s]\n", tmp->byte_code);
        i++;
        tmp = tmp->next;
    }
}

char *get_only_command(char *current_command)
{
    char *result = NULL;
    int len = 0;

    for (;current_command[len] != '\0' && current_command[len] != ' '
        && current_command[len] != '\t'; len++);
    result = malloc(len + 1);
    result[len] = '\0';
    for (int i = 0; i < len; i++) {
        result[i] = current_command[i];
    }
    return (result);
}

int fill_command_table(file_t *file, char *line)
{
    int length = 0;
    char separ[2];

    separ[0] = SEPARATOR_CHAR;
    separ[1] = '\0';
    file->command = get_only_command(line);
    if (!file->command)
        return (-1);
    length = my_strlen(file->command) + 1;
    if (length - 1 == my_strlen(line)) {
        file->args = 0;
        return (0);
    }
    file->args = my_str_to_word_array(&line[length],
        separ);
    if (!file->args)
        return (-1);
    return (0);
}

int verify_label_char(char *str, asm_t *asm_data, int *line_count)
{
    int len = 0;
    char *result = NULL;

    for (; str[len] != '\0' && str[len] != LABEL_CHAR; len++);
    if (len == my_strlen(str) && str[len] != LABEL_CHAR)
        return (0);
    result = malloc(len + 2);
    result[len + 1] = '\0';
    for (int i = 0; i < len + 1; i++)
        result[i] = str[i];
    if (is_label(result) != -1 || str[len + 1] == '\0') {
        free(result);
        return (0);
    } else if (complete_two_node(result, &str[len + 2], asm_data,
        line_count)) {
        return (0);
    }
    return (1);
}

int add_line_to_command(asm_t *asm_data, int line, int *line_counter)
{
    file_t *new = NULL;

    if (verify_label_char(asm_data->base_file[line], asm_data,
        line_counter) == 0) {
        new = add_node(&asm_data->command, line_counter);
        if (fill_command_table(new, asm_data->base_file[line]))
            return (-1);
    }
    return (0);
}