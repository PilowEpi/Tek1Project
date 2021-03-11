/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** preload_task
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

void free_task(task_t **task)
{
    task_t *tmp = *task;
    task_t *to_free = NULL;

    while (tmp != NULL) {
        to_free = tmp;
        tmp = tmp->next;
        free_my_str_array(to_free->line);
        free(to_free);
    }
}

void debug_task(task_t **task)
{
    task_t *tmp = *task;
    int i = 0;

    while (tmp != NULL) {
        my_printf("=====NODE [%d] =====\n", i);
        my_printf(" prev => %d\n", tmp->prev);
        my_printf(" node adress => %d\n", tmp);
        my_printf(" task prev => %d\n", tmp->task_prev);
        for (int i = 0; tmp->line[i]; i++)
            my_printf("%s : line [%d]\n", tmp->line[i], i);
        my_printf(" task next => %d\n", tmp->task_next);
        my_printf(" next => %d\n", tmp->next);
        i++;
        tmp = tmp->next;
    }
}

int add_task(task_t **task, char **separate, int current, int len)
{
    task_t *tmp = *task;
    task_t *new = NULL;

    if (!current && !len)
        return (-1);
    new = malloc(sizeof(task_t));
    if (!new)
        return (-2);
    new->next = NULL;
    if (tmp) {
        for (; tmp->next; tmp = tmp->next);
        tmp->next = new;
        new->prev = tmp;
    } else {
        *task = new;
        (*task)->prev = NULL;
    }
    set_task(new, separate, current, len);
    set_line(new, separate, current, len);
    return (0);
}

int fill_task(task_t **task, char **separate)
{
    int current = 0;
    int len = 0;
    int error = 0;

    for (; separate[current]; current++) {
        if (is_task(separate[current])) {
            error = add_task(task, separate, current, len);
            len = current + 1;
        }
        if (error != 0)
            return (error);
    }
    if (add_task(task, separate, current, len))
        return (-1);
    return (0);
}

int preload_task(char *line, task_t **task)
{
    char *spacing = NULL;
    char **separate = NULL;

    if (line[0] == '\0')
        return (1);
    else if (clean_str(line) == 84)
        return (84);
    if (line[0] == '\0')
        return (84);
    spacing = space_add(line, 0);
    if (spacing == NULL)
        return (84);
    separate = my_parse_shell(spacing);
    if (fill_task(task, separate)) {
        my_put_error("Invalid null command.\n");
        return (84);
    }
    free_my_str_array(separate);
    return (0);
}