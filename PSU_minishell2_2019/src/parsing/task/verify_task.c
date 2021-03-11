/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** verify_task
*/

#include "my.h"
#include "mysh.h"

int verify_empty_task(task_t *tmp)
{
    if (tmp == NULL)
        return (-1);
    if (tmp->task_prev == PIPE && !tmp->line[0]) {
        my_put_error("Invalid null command.\n");
        return (-1);
    } else if (!tmp->line[0]) {
        my_put_error("Missing name for redirect.\n");
        return (-1);
    }
    return (0);
}

int verify_task(task_t **task)
{
    task_t *tmp = *task;
    int d_redir = 0;
    int g_redir = 0;

    for (;tmp && tmp->next != NULL; tmp = tmp->next) {
        d_redir += (tmp->task_next == D_RED) ? 1 : 0;
        g_redir += (tmp->task_next == G_RED) ? 1 : 0;
        if ((tmp->line[0] == NULL) ||
            (tmp->task_prev == PIPE && tmp->task_next == G_RED))
            break;
    }
    if (verify_empty_task(tmp) == -1)
        return (-1);
    if (d_redir > 1 || g_redir > 1 ||
        (tmp->task_prev == PIPE && tmp->task_next == G_RED)) {
        my_put_error("Ambiguous output redirect.\n");
        return (-1);
    }
    return (0);
}