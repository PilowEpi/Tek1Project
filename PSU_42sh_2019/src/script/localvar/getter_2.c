/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** locale var handling
*/

#include <sys/types.h>
#include <stdlib.h>
#include <pwd.h>
#include <stdio.h>
#include <unistd.h>
#include <grp.h>
#include <string.h>
#include <sys/utsname.h>
#include <dirent.h>
#include <stddef.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "sh.h"
#include "my.h"

char *get_cwd(void)
{
    char *cwd = NULL;
    char *ret = 0;

    #ifdef _GNU_SOURCE
        cwd = get_current_dir_name();
    #else
        cwd = getcwd(cwd, 0);
    #endif
    if (!cwd)
        return (0);
    ret = my_strdup(cwd);
    free(cwd);
    return (ret);
}

char *get_euser(void)
{
    uid_t uid = geteuid();
    struct passwd *pw = getpwuid(uid);

    if (!pw)
        return (0);
    return (my_strdup(pw->pw_name));
}

char *get_locale_path_array(shell_t *shell)
{
    char *env_path = retrieve_value(shell->env, "PATH");
    char *locale_path = NULL;

    if (!env_path[0])
        return (0);
    for (int i = 0; env_path[i]; i++)
        if (env_path[i] == ':')
            env_path[i] = ' ';
    locale_path = malloc(my_strlen(env_path) + 3);
    memset(locale_path, 0, my_strlen(env_path) + 3);
    my_strcat(locale_path, "(");
    my_strcat(locale_path, env_path);
    my_strcat(locale_path, ")");
    free(env_path);
    return (locale_path);
}

char *get_execute_path(shell_t *sh)
{
    char *pwd = get_cwd();
    char *exec_name = sh->original_args[0];
    char *combi;
    int size = my_strlen(pwd) + my_strlen(exec_name) + 2;
    int trigger = 0;

    if (exec_name[0] == '/')
        return (my_strdup(exec_name));
    size = my_strncmp(exec_name, "./", 2) == 0 ? trigger++, size - 2 : size;
    combi = malloc(size);
    memset(combi, 0, size);
    my_strcat(combi, pwd);
    my_strcat(combi, "/");
    my_strcat(combi, (exec_name + (trigger ? 2 : 0)));
    return (combi);
}

char *get_ttyname(void)
{
    char *name = ttyname(STDIN_FILENO);

    while (my_strncmp(name, "pts", 3) && name)
        name++;
    return (my_strdup(name));
}