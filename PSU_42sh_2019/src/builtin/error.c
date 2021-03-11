/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** builtins error checking
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>

#include "my.h"
#include "sh.h"

int check_setenv(char **av)
{
    for (int i = 0; i < my_strlen(av[1]); i++){
        if (!is_alpha(av[1][i]) && !is_num(av[1][i])){
            write(2, VAR_NOT_AN, my_strlen(VAR_NOT_AN));
            return (1);
        }
    }
    if (!is_alpha(av[1][0])){
        write(2, VAR_BEG_LET, my_strlen(VAR_BEG_LET));
        return (1);
    }
    return (0);
}

int check_cd(char *path)
{
    struct stat buf;

    if (access(path, F_OK)){
        my_dprintf(2, "%s: No such file or directory.\n", path);
        return (1);
    }
    if (lstat(path, &buf))
        return (1);
    if (!S_ISDIR(buf.st_mode)){
        my_dprintf(2, "%s: Not a directory.\n", path);
        return (1);
    }
    return (0);
}
