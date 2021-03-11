/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_exe
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

int executable_this(char **envp, char *path, char **args, shell_t *shell)
{
    int exe_err = 0;

    exe_err = execve(path, args, envp);
    if (exe_err == -1) {
        my_put_error(path);
        my_put_error(": Permission denied.\n");
    }
    return (exe_err);
}

int verify_access(char *pathname, int option)
{
    int return_value = 0;

    return_value = access(pathname, F_OK);
    if (option && return_value == -1) {
        my_put_error(pathname);
        my_put_error(": Command not found.\n");
    }
    return (return_value);
}

char *exe_access(char **path, char *cmd)
{
    char *search_value = NULL;
    char *search_tmp = NULL;
    int access_granted = 0;

    for (int i = 0; path[i] != NULL; i++) {
        search_tmp = my_realloc_cat(path[i], "/");
        search_value = my_realloc_cat(search_tmp, cmd);
        free(search_tmp);
        access_granted = verify_access(search_value, 0);
        if (!access_granted)
            break;
        free(search_value);
    }
    if (!access_granted && search_value != NULL) {
        return (search_value);
    }
    return (0);
}

int exe_path(char **envp, char *path, char **args, shell_t *shell)
{
    int index_path = get_index_of_env(shell, "PATH");
    char *value_path = NULL;
    char *search_exe = NULL;
    char **tab = NULL;

    if (index_path != -1) {
        value_path = get_value_of_env(shell, index_path);
        tab = my_str_to_word_array(value_path);
        search_exe = exe_access(tab, path);
        if (search_exe != NULL)
            concat_exe(shell, args, search_exe, envp);
        free_my_str_array(tab);
    }
    if (search_exe == NULL || index_path == -1)
        if (!verify_access(path, 1))
            executable_this(envp, args[0], args, shell);
    free(search_exe);
    free(value_path);
    return (0);
}

void my_exe(shell_t *shell, char **args)
{
    char **envp = transform_env(&shell->env);

    if (envp && (!my_matches(args[0], "./*") ||
        !my_matches(args[0], "/*"))) {
        if (!verify_access(args[0], 1))
            executable_this(envp, args[0], args, shell);
    } else if (envp && args != NULL){
        exe_path(envp, args[0], args, shell);
    }
    free_my_str_array(envp);
}