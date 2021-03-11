/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** builtins dirs wrapper
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "sh.h"
#include "my.h"

int update_locale_dirstack(shell_t *sh)
{
    u64 size = (u64) sh->dirs->data;
    char *data = 0;
    int array_size = 2;

    for (int i = 0; i < size; i++)
        array_size += my_strlen(lld_read(sh->dirs, i) + 1);
    data = malloc(array_size);
    memset(data, 0, array_size);
    my_strcat(data, "(");
    for (int i = 0; i < size; i++) {
        my_strcat(data, lld_read(sh->dirs, i));
        my_strcat(data, " ");
    }
    my_strcat(data, ")");
    add_locale_var("dirstack", data, sh->l_var);
    return (1);
}

char *unpreprocess_dirs_home(shell_t *sh, char *path)
{
    char *home = retrieve_value(sh->env, "HOME");
    int size = my_strlen(home);
    char *new_path;

    if (!my_strncmp(home, path, size) || path[0] != '~')
        return (path);
    new_path = malloc(size + my_strlen(path));
    if (!new_path)
        return (path);
    memset(new_path, 0, my_strlen(path) + size);
    my_strcat(new_path, home);
    my_strcat(new_path, (path + 1));
    free(path);
    return (new_path);
}

char *preprocess_dirs_home(shell_t *sh, char *path)
{
    char *home = retrieve_value(sh->env, "HOME");
    int size = my_strlen(home);
    char *new_path;

    if (my_strncmp(home, path, size))
        return (path);
    new_path = malloc(my_strlen(path) - size + 2);
    if (!new_path)
        return (path);
    memset(new_path, 0, my_strlen(path) - size + 2);
    my_strcat(new_path, "~");
    my_strcat(new_path, (path + size));
    free(path);
    return (new_path);
}

lld_t *init_dirs(shell_t *sh)
{
    lld_t *dirs = lld_init();
    char *cwd = get_cwd();

    cwd = preprocess_dirs_home(sh, cwd);
    lld_insert(dirs, 0, cwd);
    return (dirs);
}

int update_dirs_cwd(shell_t *sh)
{
    char *cwd = get_cwd();
    lld_t *dirs = sh->dirs;
    char *current = (char *) lld_read(dirs, 0);

    cwd = preprocess_dirs_home(sh, cwd);
    if (!my_strcmp(current, cwd))
        return (1);
    lld_pop(dirs, 0);
    lld_insert(dirs, 0, cwd);
    return (1);
}