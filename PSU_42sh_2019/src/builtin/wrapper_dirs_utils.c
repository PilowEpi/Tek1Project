/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** builtins dirs wrapper
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "sh.h"
#include "my.h"

int dirs_conf(int *conf, char c)
{
    switch (c) {
        case 'l':
            *conf |= 0b0001;
            return (0);
        case 'v':
            *conf |= 0b0010;
            return (0);
        case 'S':
            *conf |= 0b0100;
            return (0);
        case 'c':
            *conf |= 0b1000;
            return (0);
        default:
            return (1);
    }
}

int get_conf_dirs(int ac, char **av, shell_t *sh)
{
    int c = 0;
    int conf = 0b0000;

    optind = 0;
    opterr = 0;
    while ((c = getopt(ac, av, "lvcS:")) != -1) {
        if (dirs_conf(&conf, c))
            return (-1);
    }
    c = 0;
    return (conf);
}

int clear_dirs(shell_t *sh)
{
    int size = lld_len_db(sh->dirs);

    for (int i = 1; i < size; i++)
        lld_pop(sh->dirs, i);
    return (0);
}

void print_dirs(shell_t *sh, int conf)
{
    int size = (long int) sh->dirs->data;
    char *path;

    for (int i = 0; i < size; i++) {
        path = lld_read(sh->dirs, i);
        if (conf & 0b0001)
            path = unpreprocess_dirs_home(sh, my_strdup(path));
        if (conf & 0b0010) {
            printf("%d\t%s", i, path);
            if (i + 1 < size)
                printf("\n");
        } else {
            printf("%s", path);
            if (i + 1 < size)
                printf(" ");
        }
    }
    printf("\n");
}

int wrap_dirs(int ac, char **av, shell_t *sh)
{
    int conf = get_conf_dirs(ac, av, sh);
    char *path;

    if (conf == -1)
        return (!my_dprintf(2, "Usage: dirs [-lvcS]\n"));
    if (conf & 0b1000) {
        return (clear_dirs(sh));
    }
    print_dirs(sh, conf);
    return (0);
}