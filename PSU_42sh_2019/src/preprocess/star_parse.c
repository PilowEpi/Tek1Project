/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** star parsing
*/

#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include "my.h"
#include "sh.h"

char *get_pattern(char *cmd, int i)
{
    int start = i;
    int end = i;
    char *pattern = 0;

    while (cmd[start] != ' ' && cmd[start] != '/' && start > 0)
        start--;
    while (cmd[end] != ' ' && cmd[end] != '/' && cmd[end] != 0)
        end++;
    pattern = substr(cmd, start + 1, end);
    return (pattern);
}

char *get_folder(char *cmd, int i)
{
    int start = i;
    int end = i;
    char *pattern = 0;

    while (cmd[start] != ' ' && start > 0)
        start--;
    while (cmd[end] != ' ' && cmd[end] != '/' && cmd[end] != 0)
        end++;
    end--;
    while (cmd[end] != '/' && cmd[end] != ' ' && end > 0)
        end--;
    if (end == start)
        return (my_strdup("."));
    pattern = substr(cmd, start + 1, end + 1);
    return (pattern);
}

char *get_append(char *cmd, int i)
{
    int start = i;
    int end = i;
    char *pattern = 0;

    while (cmd[start] != ' ' && cmd[start] != '/' && cmd[start] != 0)
        start++;
    end = start;
    while (cmd[end] != ' ' && cmd[end] != 0)
        end++;
    if (end == start)
        return (my_strdup(""));
    pattern = substr(cmd, start, end);
    return (pattern);
}

int match(char const *s1, char const *s2)
{
    if (*s2 == '\0' && *s1 == '\0')
        return (1);
    if ((*s1 == '\0' || *s1 != *s2) && *s2 != '*')
        return (0);
    if (*s2 == '*' && *s1 != '\0')
        return (match(s1 + 1, s2) || match(s1, s2 + 1));
    if (*s2 == '*' && *s1 == '\0')
        return (match(s1, s2 + 1));
    return (match(s1 + 1, s2 + 1));
}

char *merge_dir(char *str_a, char *str_b, char *str_c)
{
    size_t len_a = my_strlen(str_a);
    size_t len_b = my_strlen(str_b);
    size_t len_c = my_strlen(str_c);
    char *res = malloc(sizeof(char) * (len_a + len_b + len_c + 1));

    if (!res)
        return (0);
    if (my_strcmp(str_a, ".")) {
        my_memcpy(res, str_a, len_a);
        my_memcpy(res + len_a, str_b, len_b);
        my_memcpy(res + len_a + len_b, str_c, len_c);
        res[len_a + len_b + len_c] = 0;
    } else {
        my_memcpy(res, str_b, len_b);
        my_memcpy(res + len_b, str_c, len_c);
        res[len_b + len_c] = 0;
    }
    return (res);
}
