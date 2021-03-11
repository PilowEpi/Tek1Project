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

int nb_len(int nb)
{
    int len = 0;

    while (nb > 0) {
        nb /= 10;
        len++;
    }
    return (len);
}

char *my_nts(int nb)
{
    char *str;
    int len = nb_len(nb);
    int pos = len - 1;

    if (nb == 0)
        return (my_strdup("0"));
    str = malloc((len + 1) * sizeof(char));
    str[len] = 0;
    while (nb > 0) {
        str[pos] = (nb % 10) + '0';
        nb /= 10;
        pos--;
    }
    return (str);
}