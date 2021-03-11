/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** Exec functions
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "my.h"
#include "sh.h"

void prepare_child(cmd_t *cmd, int i)
{
    for (int j = 0; cmd->pipes[j] != -1; j++){
        if (cmd->pipes[j] != cmd->connections[i * 2 + 0] &&
            cmd->pipes[j] != cmd->connections[i * 2 + 1])
            close(cmd->pipes[j]);
    }
    dup2(cmd->connections[i * 2 + 0], 0);
    dup2(cmd->connections[i * 2 + 1], 1);
}

int wait_parent(int pid, shell_t *sh)
{
    int status;

    if (!pid)
        return (0);
    waitpid(pid, &status, 0);
    if (WTERMSIG(status) == 8 && WCOREDUMP(status))
        my_dprintf(2, "Floating exception (core dumped)\n");
    if (WTERMSIG(status) == 11 && WCOREDUMP(status))
        my_dprintf(2, "Segmentation fault (core dumped)\n");
    if (WTERMSIG(status) == 8 && !WCOREDUMP(status))
        my_dprintf(2, "Floating exception\n");
    if (WTERMSIG(status) == 11 && !WCOREDUMP(status))
        my_dprintf(2, "Segmentation fault\n");
    if (sh) {
        sh->exit_code = status;
        set_locale_status(sh, sh->exit_code);
    }
    return (0);
}

int parent(int i, int pid, cmd_t *cmd, char **av)
{
    if (cmd->commands[i + 1] != 0){
        for (int j = 0; av[j] != 0; j++)
            free(av[j]);
        free(av);
        return (0);
    }
    for (int j = 0; cmd->pipes[j] != -1; j++)
        close(cmd->pipes[j]);
    for (int j = 0; av[j] != 0; j++)
        free(av[j]);
    free(av);
    return (pid);
}

void call_execve(char **av, char **envp)
{
    char *filepath = 0;
    char **paths = get_paths(envp);

    check_script(av, envp);
    try_exec(av[0], av, envp);
    filepath = get_filepath(av[0], "/bin/");
    try_exec(filepath, av, envp);
    free(filepath);
    for (int i = 0; paths && paths[i] != 0; i++){
        filepath = get_filepath(av[0], paths[i]);
        try_exec(filepath, av, envp);
        free(filepath);
        free(paths[i]);
    }
    free(paths);
    my_dprintf(2, "%s: Command not found.\n", av[0]);
    exit(-1);
}

int child(int i, cmd_t *cmd, shell_t *sh, char **av)
{
    prepare_child(cmd, i);
    if (!av)
        return (-1);
    call_execve(av, sh->env);
    return (-1);
}
