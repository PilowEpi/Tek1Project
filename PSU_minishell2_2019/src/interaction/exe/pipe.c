/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** pipe
*/

#include <stddef.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include "my.h"
#include "mysh.h"

int next_pipe(task_t *task, shell_t *shell)
{
    int exe_err = 0;
    int status = 0;
    int pid = 0;

    if (pipe(task->pipe) == -1)
        return (-1);
    pid = fork();
    if (pid == 0) {
        dup2(task->pipe[1], STDOUT_FILENO);
        close(task->pipe[0]);
        exe_err = command_listing(task->line[0], task->line, shell);
        exit(exe_err);
    }
    waitpid(pid, &status, WNOHANG);
    return (0);
}

int middle_pipe(task_t *task, shell_t *shell)
{
    int exe_err = 0;
    int status = 0;
    int pid = 0;

    if (pipe(task->pipe) == -1)
        return (-1);
    pid = fork();
    if (pid == 0) {
        dup2(task->prev->pipe[0], STDIN_FILENO);
        close(task->prev->pipe[1]);
        dup2(task->pipe[1], STDOUT_FILENO);
        close(task->pipe[0]);
        exe_err = command_listing(task->line[0], task->line, shell);
        exit(exe_err);
    }
    close(task->prev->pipe[0]);
    close(task->prev->pipe[1]);
    waitpid(pid, &status, WNOHANG);
    return (0);
}

int prev_pipe(task_t *task, shell_t *shell)
{
    int status = 0;
    int exe_err = 0;
    int pid = 0;

    pid = fork();
    if (pid == 0) {
        dup2(task->prev->pipe[0], STDIN_FILENO);
        close(task->prev->pipe[1]);
        exe_err = command_listing(task->line[0], task->line, shell);
        exit(exe_err);
    }
    if (task->prev->pipe[0] && task->prev->pipe[0]) {
        close(task->prev->pipe[0]);
        close(task->prev->pipe[1]);
    }
    waitpid(pid, &status, 0);
    print_status(status, shell);
    return (0);
}