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

char *get_fullpath(char *path, shell_t *sh)
{
    char *result = unpreprocess_dirs_home(sh, path);

    return (result);
}

int move_popd(char *path, shell_t *sh, int conf)
{
    if (!chdir(get_fullpath(lld_read(sh->dirs, 0), sh))) {
        free(old_pwd);
        old_pwd = my_strdup(lld_read(sh->dirs, 0));
    }
    if (set_env(sh, "OLDPWD", old_pwd))
        return (1);
    return (end_cd(sh));
}

int exec_popd(int info[3], int conf[2], shell_t *sh, char *path)
{
    int num = conf[1];

    if (info[0] && num >= (long int) sh->dirs->data)
        return (!my_dprintf(2, "popd: Directory stack not that deep.\n"));
    if (info[0])
        free(lld_pop(sh->dirs, num));
    else if (info[2] && (long int) sh->dirs->data > 1) {
        if (check_cd(get_fullpath(lld_read(sh->dirs, 1), sh)))
            return (0);
        free(lld_pop(sh->dirs, 0));
    }
    print_dirs(sh, conf[0]);
    if (my_strcmp(path, lld_read(sh->dirs, 0))) {
        return (move_popd(lld_read(sh->dirs, 0), sh, conf[0]));
    }
    return (0);
}

int wrap_popd(int ac, char **av, shell_t *sh)
{
    int conf[2] = {0, 0};
    int *info = malloc(sizeof(int) * 3);
    char *path;

    if (!info) return (1);
    get_pushd_info(ac, av, info);
    conf[0] = get_conf_pushd(ac, av, sh);
    if (ac == 1)
        info[2] = 1;
    if (ac == 1 && (long int) sh->dirs->data == 1)
        return (!my_dprintf(2, "popd: Directory stack empty.\n"));
    if (info[1] || info[0] && info[2] || info[0] > 1 || conf[0] == -1)
        return (!my_dprintf(2, "Usage: popd [-plvn] [-|+<n>].\n"));
    path = my_strdup(lld_read(sh->dirs, 0));
    for (int i = 1; i < ac; i++)
            if (av[i][0] == '+')
                conf[1] = atoi((av[i] + 1));
    return (exec_popd(info, conf, sh, path));
}
