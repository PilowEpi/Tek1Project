/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** builtins dirs wrapper pushd
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "sh.h"
#include "my.h"

int pushd_conf(int *conf, char c)
{
    switch (c) {
        case 'l':
            *conf |= 0b0001;
            return (0);
        case 'v':
            *conf |= 0b0010;
            return (0);
        case 'n':
            *conf |= 0b0100;
            return (0);
        case 'p':
            *conf |= 0b1000;
            return (0);
        default:
            return (1);
    }
}

int get_conf_pushd(int ac, char **av, shell_t *sh)
{
    int c;
    int conf = 0b0000;

    optind = 0;
    opterr = 0;
    if (ac == 1)
        return (0b0000);
    while ((c = getopt(ac, av, "lvpn")) != -1) {
        if (pushd_conf(&conf, c))
            return (-1);
    }
    return (conf);
}

int *get_pushd_info(int ac, char **av, int *info)
{
    info[0] = 0;
    info[1] = 0;
    info[2] = 0;
    for (int i = 1; i < ac; i++) {
        if (av[i][0] == '+') {
            info[0]++;
            continue;
        }
        if (av[i][0] != '-') {
            info[1]++;
            continue;
        }
        if (av[i][0] == '-' && !av[i][1]) {
            info[2]++;
            continue;
        }
    }
    return (info);
}

int pushd_owd(shell_t *sh, int conf)
{
    char *path = ((long int) sh->dirs->data > 1) ?
    lld_read(sh->dirs, 1) : get_lvar(sh->l_var, "home");

    if (check_cd(path))
        return (0);
    if (!chdir(path))
        free(old_pwd), old_pwd = my_strdup(lld_read(sh->dirs, 0));
    lld_insert(sh->dirs, 0, my_strdup(path));
    if (set_env(sh, "OLDPWD", old_pwd))
        return (1);
    print_dirs(sh, conf);
    return (end_cd(sh));
}