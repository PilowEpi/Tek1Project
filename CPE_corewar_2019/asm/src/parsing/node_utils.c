/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** node_utils
*/

#include <stdlib.h>

#include "my.h"
#include "corewar.h"

file_t *add_node(file_t **head, int *line_counter)
{
    file_t *new = malloc(sizeof(file_t));
    file_t *tmp = *head;

    if (!new)
        return (NULL);
    new->next = NULL;
    new->line = *line_counter;
    if (tmp) {
        for (; tmp->next; tmp = tmp->next);
        tmp->next = new;
        new->prev = tmp;
    } else {
        *head = new;
        (*head)->prev = NULL;
    }
    return (new);
}

int complete_two_node(char *lab, char *cmd, asm_t *asm_data, int *line_counter)
{
    file_t *label = add_node(&asm_data->command, line_counter);
    file_t *command = add_node(&asm_data->command, line_counter);

    if (fill_command_table(label, lab))
            return (-1);
    free(lab);
    if (fill_command_table(command, cmd))
            return (-1);
    return (0);
}