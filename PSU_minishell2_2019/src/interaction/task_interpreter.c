/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** task_interpreter
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "my.h"
#include "mysh.h"

int choose_task(task_t *task, shell_t *shell)
{
    if (task->task_prev == NOTHING && task->task_next == NOTHING)
        return (simple_listing(task->line[0], task->line, shell));
    if (task->task_prev == NOTHING && task->task_next == PIPE)
        return (next_pipe(task, shell));
    if (task->task_prev == PIPE && task->task_next == NOTHING)
        return (prev_pipe(task, shell));
    if (task->task_prev == PIPE && task->task_next == PIPE)
        return (middle_pipe(task, shell));
    if (task->task_next == D_RED)
        return (prev_rigth_redir(task, shell));
    if (task->task_next == D_D_RED)
        return (prev_d_rigth_red(task, shell));
    if (task->task_prev == G_RED && task->task_next == NOTHING)
        return (prev_left_redir(task->prev, shell));
    return (0);
}

int load_task(task_t **task, shell_t *shell)
{
    task_t *tmp = *task;
    int error = 0;

    for (;tmp; tmp = tmp->next) {
        if (tmp->next == NULL && !my_strcmp(tmp->line[0], "exit")) {
            my_exit(shell, tmp->line);
            continue;
        }
        error = choose_task(tmp, shell);
        if (error)
            break;
    }
    return (0);
}

int task_interpreter(char *input, shell_t *shell)
{
    char **separate = my_str_to_word_array(input);
    task_t *task = NULL;
    int task_error = 0;

    for (int i = 0; separate[i] != NULL;i++) {
        if (preload_task(separate[i], &task) == 84) {
            free_my_str_array(separate);
            return (84);
        }
        task_error = verify_task(&task);
        if (task_error == -1)
            continue;
        else if (task_error == 84 || load_task(&task, shell) == 84)
            return (84);
        free_task(&task);
        task = NULL;
    }
    free_my_str_array(separate);
    return (0);
}