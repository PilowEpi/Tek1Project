/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_cd_list
*/

#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <stddef.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "my.h"
#include "mysh.h"

char *go_to_path(char const *path)
{
    char new_path[512];

    if (getcwd(new_path, sizeof(new_path)) == NULL) {
            my_printf("%s: ", path);
            perror(NULL);
            return (NULL);
    }
    return (my_strdup(new_path));
}

char **fill_env_array(char *name, char *path)
{
    char **env = malloc(sizeof(char *) * 4);

    if (env == NULL)
        return (NULL);
    env[0] = my_strdup("cd");
    env[1] = my_strdup(name);
    env[2] = my_strdup(path);
    env[3] = NULL;
    return (env);
}

int set_pwd(shell_t *shell, char *path)
{
    int index_pwd = get_index_of_env(shell, "PWD");
    char *actual_pwd = get_value_of_env(shell, index_pwd);
    char **pwd = fill_env_array("PWD", path);
    char **old_pwd = NULL;

    if (index_pwd != -1) {
        old_pwd = fill_env_array("OLDPWD", actual_pwd);
        if (pwd == NULL && old_pwd == NULL)
            return (84);
    } else {
        old_pwd = fill_env_array("OLDPWD", path);
        if (pwd == NULL && old_pwd == NULL)
            return (84);
    }
    my_setenv_list(shell, old_pwd);
    my_setenv_list(shell, pwd);
    return (0);
}

void my_cd_list(shell_t *shell, char *path)
{
    char *new_path = NULL;

    if (chdir(path) != 0) {
        my_put_error(path);
        my_put_error(": No such file or directory.\n");
    } else {
        new_path = go_to_path(path);
        if (new_path == NULL)
            my_exit(shell, NULL);
        if (set_pwd(shell, new_path) == 84)
            my_exit(shell, NULL);
    }
}