/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** redir
*/

#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"
#include "mysh.h"

int prev_rigth_redir(task_t *task, shell_t *shell)
{
    int new_fd = 0;
    int backup = dup(1);
    int pid = 0;
    int exe_err = 0;

    close(1);
    new_fd = open(task->next->line[0], O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (new_fd < 0) return (-1);
    pid = fork();
    if (pid == 0) {
        if (task->task_prev != NOTHING) {
            dup2(task->prev->pipe[0], STDIN_FILENO);
            close(task->prev->pipe[1]);
        }
        exe_err = command_listing(task->line[0], task->line, shell);
        exit(exe_err);
    }
    close(new_fd);
    dup2(backup, 1);
    return (0);
}

int prev_d_rigth_red(task_t *task, shell_t *shell)
{
    int new_fd = 0;
    int backup = dup(1);
    int pid = 0;
    int exe_err = 0;

    close(1);
    new_fd = open(task->next->line[0], O_CREAT | O_WRONLY | O_APPEND, 0644);
    if (new_fd < 0) return (-1);
    pid = fork();
    if (pid == 0) {
        if (task->task_prev != NOTHING) {
            dup2(task->prev->pipe[0], 0);
            close(task->prev->pipe[1]);
        }
        exe_err = command_listing(task->line[0], task->line, shell);
        exit(exe_err);
    }
    close(new_fd);
    dup2(backup, 1);
    return (0);
}

int prev_left_redir(task_t *task, shell_t *shell)
{
    int new_fd = 0;
    int pid = 0;
    int backup = dup(0);
    int exe_err = 0;

    close(0);
    if ((new_fd = open(task->next->line[0], O_RDONLY)) < 0) {
        my_put_error(task->next->line[0]);
        my_put_error(": No such file or directory.\n");
        dup2(backup, 0);
        return (-1);
    }
    pid = fork();
    if (pid == 0) {
        exe_err = command_listing(task->line[0], task->line, shell);
        exit(exe_err);
    }
    dup2(backup, 0);
    waitpid(pid, 0, 0);
    return (0);
}