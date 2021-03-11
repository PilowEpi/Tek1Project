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

int add_locale_var(char *name, char *inf, lld_t *l_var)
{
    char **info = create_info(name, inf);
    u64 size = (u64) l_var->data;
    char **data;

    if (!info)
        return (1);
    for (int i = 0; i < size; i++)
        if (!my_strcmp(info[0], ((char **) lld_read(l_var, i))[0])) {
            data = (char **) lld_pop(l_var, i);
            free(data[0]);
            free(data[1]);
            free(data);
            break;
        }
    lld_insert(l_var, 0, info);
    return (0);
}

int l_var_add_userinf(lld_t *l_var)
{
    int status = 0;
    char *user = get_user();
    char *euser = get_euser();
    char *gname = get_gname();

    if (user)
        status |= add_locale_var("user", user, l_var);
    if (euser)
        status |= add_locale_var("euser", euser, l_var);
    if (gname)
        status |= add_locale_var("group", gname, l_var);
    status |= add_locale_var("euid", get_euid(), l_var);
    status |= add_locale_var("uid", get_uid(), l_var);
    status |= add_locale_var("gid", get_gid(), l_var);
    return (status);
}

int l_var_add_system(lld_t *l_var)
{
    struct utsname buf;
    int status = 0;

    if (uname(&buf)) {
        return (1);
    }
    status |= add_locale_var("OSTYPE", my_strdup(buf.sysname), l_var);
    status |= add_locale_var("OSREL", my_strdup(buf.release), l_var);
    status |= add_locale_var("OSVER", my_strdup(buf.version), l_var);
    #ifdef _GNU_SOURCE
        status |= add_locale_var("DOMAIN", my_strdup(buf.__domainname), l_var);
    #endif
    return (0);
}

char *get_lvar(lld_t *l_var, char *name)
{
    char **properties;
    long int len = lld_len_db(l_var);

    for (int i = 0; i < len; i++) {
        properties = (char **) lld_read(l_var, i);
        if (properties && properties[0] && !my_strcmp(properties[0], name))
            return (my_strdup(properties[1]));
    }
    return (NULL);
}

char *get_home(shell_t *sh)
{
    char *home = retrieve_value(sh->env, "HOME");
    DIR *home_dir;
    struct dirent *dir;
    char *user = get_lvar(sh->l_var, "user");
    char *path = 0;

    if (home && home[0])
        return (home);
    home_dir = opendir("/home");
    user = !user ? get_lvar(sh->l_var, "euser") : user;
    if (!home_dir || !user)
        return (0);
    for (dir = readdir(home_dir); dir; dir = readdir(home_dir))
        if (!my_strcmp(dir->d_name, user)) {
            path = malloc(my_strlen(dir->d_name) + 7);
            memset(path, 0, my_strlen(dir->d_name) + 7);
            my_strcat(path, "/home/");
            my_strcat(path, dir->d_name);
        }
    return (path);
}