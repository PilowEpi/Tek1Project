/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** builtins dirs wrapper function pushd
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "sh.h"
#include "my.h"

int pushd_plus(int ac, char **av, shell_t *sh, int conf)
{
    char *data;
    for (int num = 0, i = 1; i < ac; i++) {
        if (av[i][0] != '+') continue;
        num = atoi((av[i] + 1));
        if (!num)
            return (!my_dprintf(2, "%s: No such file or directory.\n", av[i]));
        if (num > (long int) sh->dirs->data)
            return (!my_dprintf(2, "pushd: Directory stack not that deep.\n"));
        if (check_cd(get_fullpath(lld_read(sh->dirs, num), sh))) return (0);
        for (int y = 0; y < num; y++) {
            data = lld_pop(sh->dirs, 0);
            lld_insert(sh->dirs, (long int) sh->dirs->data, data);
        }
        if (!chdir(get_fullpath(lld_read(sh->dirs, 0), sh)))
            free(old_pwd), old_pwd = my_strdup(lld_read(sh->dirs, 0));
        if (set_env(sh, "OLDPWD", old_pwd))
            return (1);
        print_dirs(sh, conf);
        return (end_cd(sh));
    }
}

int pushd_dir(int ac, char **av, shell_t *sh, int conf)
{
    char *path;

    for (int i = 1; i < ac; i++)
        if (av[i][0] != '+' && av[i][0] != '-') {
            path = av[i];
            break;
        }
    if (check_cd(path))
        return (0);
    lld_insert(sh->dirs, 0, my_strdup(path));
    if (!chdir(path))
        free(old_pwd), old_pwd = my_strdup(path);
    if (set_env(sh, "OLDPWD", old_pwd))
        return (1);
    print_dirs(sh, conf);
    return (end_cd(sh));
}

int pushd_noarg(shell_t *sh, int conf)
{
    char *data_1;

    if (check_cd(lld_read(sh->dirs, 1)))
        return (0);
    data_1 = lld_pop(sh->dirs, 1);
    lld_insert(sh->dirs, 0, data_1);
    if (!chdir(data_1))
        free(old_pwd), old_pwd = my_strdup(data_1);
    if (set_env(sh, "OLDPWD", old_pwd))
        return (1);
    print_dirs(sh, conf);
    return (end_cd(sh));
}

int wrap_pushd(int ac, char **av, shell_t *sh)
{
    int *info = malloc(sizeof(int) * 3);
    int conf = get_conf_pushd(ac, av, sh);
    char *path = 0;

    if (!info) return (1);
    get_pushd_info(ac, av, info);
    if (ac == 1 && (long int) sh->dirs->data == 1)
        return (!my_dprintf(2, "pushd: No other directory.\n"));
    if (ac == 1) return (pushd_noarg(sh, conf));
    if (((info[0] + info[1] + info[2]) > 1) || info[0] > 1 || info[1] > 1)
        return (!my_dprintf(2, "pushd: Too many arguments.\n"));
    if (conf == -1 || info[2] && (info[1] || info[0]))
        return (!my_dprintf(2, "Usage: pushd [-plvn] [-|<dir>|+<n>].\n"));
    if (info[0]) return (pushd_plus(ac, av, sh, conf));
    if (info[1]) return (pushd_dir(ac, av, sh, conf));
    if (info[2]) return (pushd_owd(sh, conf));
    return (0);
}