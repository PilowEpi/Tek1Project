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

char *get_user(void)
{
    uid_t uid = getuid();
    struct passwd *pw = getpwuid(uid);

    if (!pw)
        return (0);
    return (my_strdup(pw->pw_name));
}

char *get_euid(void)
{
    uid_t uid = geteuid();
    char tmp[20];
    int size = 0;

    size = sprintf(tmp, "%d", uid);
    tmp[size] = 0;
    return (my_strdup(tmp));
}

char *get_uid(void)
{
    uid_t uid = getuid();
    char tmp[20];
    int size = 0;

    size = sprintf(tmp, "%d", uid);
    tmp[size] = 0;
    return (my_strdup(tmp));
}

char *get_gid(void)
{
    gid_t gid = getgid();
    char tmp[20];
    int size = 0;

    size = sprintf(tmp, "%d", gid);
    tmp[size] = 0;
    return (my_strdup(tmp));
}

char *get_gname(void)
{
    gid_t gid = getgid();
    struct group *gr = NULL;

    gr = getgrgid(gid);
    if (!gr)
        return (0);
    return (my_strdup(gr->gr_name));
}