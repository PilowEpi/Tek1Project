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

char **read_file_lines(char *file)
{
    FILE *f = fopen(file, "r");
    char *line = 0;
    char **data;
    size_t size = 1;
    size_t index = 0;
    size_t len = 0;
    ssize_t read = 0;

    if (f == NULL) return (0);
    while (read = getline(&line, &len, f)) {
        size++;
        data = realloc(data, sizeof(char *) * size);
        if (!data) return (0);
        data[index++] = my_strdup(line);
    }
    if (size > 1)
        data[index] = 0;
    free(line);
    return (data);
}

int remove_l_var(shell_t *sh, char *name)
{
    u64 size = (u64) sh->l_var->data;
    char **data = 0;

    for (int i = 0; i < size; i++) {
        data = lld_read(sh->l_var, i);
        if (my_strcmp(data[0], name))
            continue;
        lld_pop(sh->l_var, i);
        return (0);
    }
    return (1);
}

int set_locale_status(shell_t *sh, int status)
{
    u64 size = lld_len(sh->l_var);
    char **data = 0;

    for (int i = 0; i < size; i++) {
        data = lld_read(sh->l_var, i);
        if (my_strcmp(data[0], "status"))
            continue;
        free(data[1]);
        data[1] = my_nts(status);
        return (0);
    }
    return (1);
}

char **create_info(char *name, char *inf)
{
    char **info = malloc(sizeof(char *) * 2);

    info[0] = my_strdup(name);
    info[1] = my_strdup(inf);
    free(inf);
    return (info);
}

int del_locale_var(char *name, lld_t *l_var)
{
    u64 size = (u64) l_var->data;
    char **data;

    for (int i = 0; i < size; i++) {
        data = (char **) lld_read(l_var, i);
        if (!my_strcmp(data[0], name)) {
            lld_pop(l_var, i);
            return (0);
        }
    }
    return (1);
}
