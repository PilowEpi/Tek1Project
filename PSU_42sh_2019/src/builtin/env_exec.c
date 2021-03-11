/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** env exec calls
*/

#include <stdlib.h>
#include <unistd.h>

#include "sh.h"

int exec_env_from(char **env, char **av, int ac, int from)
{
    int new_ac = ac - from;
    char **new_av = malloc(sizeof(char *) * new_ac);
    int pid;
    shell_t ret;

    if (!new_av)
        return (1);
    for (int i = from; i < ac; i++)
        new_av[i - from] = av[i];
    if (pid = fork())
        wait_parent(pid, &ret);
    else
        call_execve(new_av, env);
    free(new_av);
    return (0);
}
