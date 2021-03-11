/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** identifier_task
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

int is_task(char const *str)
{
    char *tab[] = {"|", ">", "<", ">>", "<<", 0};

    for (int i = 0; tab[i]; i++) {
        if (!my_strcmp(str, tab[i]))
            return (1);
    }
    return (0);
}

type_t get_task(char const *str)
{
    char *tab[] = {"|", ">", "<", ">>", "<<", 0};
    type_t t_tab[] = {PIPE, D_RED, G_RED, D_D_RED, G_D_RED, NOTHING};

    for (int i = 0; tab[i]; i++) {
        if (!my_strcmp(str, tab[i]))
            return (t_tab[i]);
    }
    return (NOTHING);
}

int set_task(task_t *task, char **separate, int current, int len)
{
    task->task_prev = ALLOC;
    task->task_next = ALLOC;
    if (!current || (len - 1 < 0))
        task->task_prev = NOTHING;
    if (!separate[current])
        task->task_next = NOTHING;
    if (task->task_prev != NOTHING)
        task->task_prev = get_task(separate[len - 1]);
    if (task->task_next != NOTHING)
        task->task_next = get_task(separate[current]);
    return (0);
}

int set_line(task_t *task, char **separate, int current, int len)
{
    int length = current - len + 1;
    int loop = 0;

    task->line = malloc(sizeof(char *) * length);
    if (!task->line)
        exit(84);
    task->line[length - 1] = NULL;
    for (int i = current - length + 1; i < current; i++, loop++) {
        task->line[loop] = my_strdup(separate[i]);
    }
    return (0);
}