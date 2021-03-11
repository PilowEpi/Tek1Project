/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** remove_comment
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"

int clean_comment(char **line, int len)
{
    char *clean_str = malloc(sizeof(char) * len + 1);

    if (!clean_str)
        return (84);
    clean_str[len] = '\0';
    for (int i = 0; i < len; i++) {
        clean_str[i] = (*line)[i];
    }
    free(*line);
    *line = clean_str;
    return (0);
}

int check_comment(char *line)
{
    int alpha = 0;
    int hash = 0;
    int count = 0;

    for (int i = 0; line[i]; i++) {
        if (line[i] == '#')
            hash = (hash == 0) ? 1 : 0;
        if (!hash && (is_alpha(line[i]) || is_num(line[i])))
            alpha = 1;
    }
    if (!hash && alpha)
        return (0);
    else if (hash && !alpha)
        return (-1);
    for (; line[count] && line[count] != '#'; count++);
    if (!count || count == my_strlen(line))
        return (0);
    return (count);
}

int remove_comment(char *line)
{
    int state;
    int count = 0;

    state = check_comment(line);
    if (state == -1) {
        return (clean_comment(&line, 0));
    } else if (state != 0) {
        return (clean_comment(&line, state));
    }
    return (0);
}