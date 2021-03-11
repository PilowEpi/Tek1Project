/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** alias handling
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

lld_t *init_alias(void)
{
    lld_t *alias = lld_init();

    return (alias);
}

int array_size(char **array)
{
    int size;

    for (size = 0; array[size] != NULL; size++);
    return (size);
}

char *create_sh_array(char **array)
{
    int size = 2;
    char *line_array;

    for (int i = 0; array[i]; i++)
        size += my_strlen(array[i]) + 1;
    line_array = malloc(size);
    if (!line_array) return NULL;
    my_strcat(line_array, "(");
    for (int i = 0; array[i]; i++) {
        my_strcat(line_array, array[i]);
        if (array[i + 1] != NULL)
            my_strcat(line_array, " ");
    }
    my_strcat(line_array, ")");
    return (line_array);
}

int add_alias(lld_t *alias, char *line)
{
    char **alias_cmd = my_str_to_word_array(line);
    char **data;
    int size = array_size(alias_cmd);

    if (my_strcmp(alias_cmd[0], "alias") || size < 3)
        return (1);
    data = malloc(sizeof(char *) * 2);
    if (!data) return (1);
    data[0] = my_strdup(alias_cmd[1]);
    if (size == 3)
        data[1] = my_strdup(alias_cmd[2]);
    else
        data[1] = create_sh_array(alias_cmd + 2);
    if (!data[1]) return (1);
    lld_insert(alias, 0, data);
    return (0);
}
