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

int load_config(lld_t *l_var, shell_t *sh, char *path)
{
    char **lines = read_file_lines(path);

    if (!lines)
        return (1);
    for (int i = 0; lines && lines[i]; i++) {
        if (lines[i][0] == '#')
            continue;
    }
}

void write_default_config(char *default_config)
{
}

int load_file_configuration(lld_t *l_var, shell_t *sh)
{
    char *dir = get_lvar(l_var, "dir");
    char *default_config = malloc(strlen(dir) + 7);
    int status = 0;

    memset(default_config, 0, strlen(dir) + 7);
    my_strcat(default_config, dir);
    my_strcat(default_config, "/.42sh");
    status |= load_config(l_var, sh, default_config);
    if (status)
        write_default_config(default_config);
    return (0);
}
