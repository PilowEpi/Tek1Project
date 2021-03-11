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

int init_l_var(lld_t *l_var, shell_t *sh)
{
    int status = 0;

    status |= l_var_add_userinf(l_var);
    status |= l_var_add_system(l_var);
    status |= l_var_add_current(l_var, sh);
    if (!get_lvar(l_var, "dir")) {
        resolve_dir_path(l_var, sh);
    }
    if (get_lvar(l_var, "dir")) {
        status |= load_file_configuration(l_var, sh);
    }
    if (sh->original_args[1] && sh->original_args[2] &&
        access(sh->original_args[1], F_OK) == 0) {
        status |= l_var_add_argv(sh, l_var);
    }
    return (status);
}

int sort_l_var(void *obj, void *obj_2)
{
    char *name_1 = ((char **) obj)[0];
    char *name_2 = ((char **) obj_2)[0];

    return (my_strcmp(name_1, name_2));
}

int print_locale_variable(lld_t *l_var)
{
    char **properties;
    long int len = lld_len_db(l_var);

    for (int i = 0; i < len; i++) {
        properties = (char **) lld_read(l_var, i);
        printf("%s\t%s\n", properties[0], properties[1]);
    }
    return (0);
}

void sort_locale_variable(lld_t *l_var)
{
    lld_sort(l_var, &sort_l_var);
}

lld_t *locale_variables_init(shell_t *shell)
{
    lld_t *l_var = lld_init();
    if (init_l_var(l_var, shell))
        dprintf(2, "An error occured while initializing locale variables !\n");
    sort_locale_variable(l_var);
    return (l_var);
};
