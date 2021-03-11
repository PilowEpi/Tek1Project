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

int l_var_add_current(lld_t *l_var, shell_t *sh)
{
    int status = 0;
    char *locale_path = get_locale_path_array(sh);
    char *exec_path = get_execute_path(sh);
    char *home = retrieve_value(sh->env, "HOME");

    status |= add_locale_var("cwd", get_cwd(), l_var);
    status |= add_locale_var("dirstack", get_cwd(), l_var);
    status |= add_locale_var("status", my_strdup("0"), l_var);
    if (locale_path)
        status |= add_locale_var("path", locale_path, l_var);
    if (exec_path)
        status |= add_locale_var("shell", exec_path, l_var);
    if (isatty(0))
        status |= add_locale_var("tty", get_ttyname(), l_var);
    if (home  && home[0])
        status |= add_locale_var("dir", home, l_var);
    status |= add_locale_var("histchar", my_strdup("!"), l_var);
    status |= add_locale_var("version", my_strdup(VERSION), l_var);
    return (status);
}

void resolve_dir_path(lld_t *l_var, shell_t *sh)
{
    DIR *home_dir = opendir("/home");
    struct dirent *dir;
    char *user = get_lvar(l_var, "user");
    char *path;

    if (!user)
        user = get_lvar(l_var, "euser");
    if (!home_dir || !user)
        return;
    for (dir = readdir(home_dir); dir; dir = readdir(home_dir)) {
        if (my_strcmp(dir->d_name, user) != 0)
            continue;
        path = malloc(my_strlen(dir->d_name) + 7);
        memset(path, 0, my_strlen(dir->d_name) + 7);
        my_strcat(path, "/home/");
        my_strcat(path, dir->d_name);
        add_locale_var("dir", path, l_var);
    }
}

char **copy_array(char **array)
{
    int count = 0;
    char **new_array;

    for (int i = 0; array[i] != NULL; i++) {
        count++;
    }
    new_array = malloc(sizeof(char *) * (count + 1));
    for (int i = 0; array[i] != NULL; i++) {
        new_array[i] = my_strdup(array[i]);
    }
    new_array[count] = 0;
    return (new_array);
}

int l_var_add_argv(shell_t *sh, lld_t *l_var)
{
    char **new_array = copy_array((sh->original_args + 2));
    int size = 2;
    char *argv;

    for (int i = 0; new_array[i]; i++)
        size += my_strlen(new_array[i]) + 1;
    argv = malloc(size);
    memset(argv, 0, size);
    my_strcat(argv, "(");
    for (int i = 0; new_array[i]; i++) {
        my_strcat(argv, new_array[i]);
        if (new_array[i + 1])
            my_strcat(argv, " ");
        free(new_array[i]);
    }
    my_strcat(argv, ")");
    add_locale_var("argv", argv, l_var);
    return (0);
}
