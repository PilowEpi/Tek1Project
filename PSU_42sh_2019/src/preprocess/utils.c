/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** preprocess utils
*/

#include <stdlib.h>
#include "my.h"
#include "sh.h"

int get_varname_index(char *at)
{
    char waited = at[1] == '{' ? '}' : ' ';
    int index = 0;

    while (at[index] != waited && at[index] != 0)
        index++;
    return (index);
}

char *check_par(char *str)
{
    size_t len = my_strlen(str);

    if (!str)
        return (0);
    if (str[0] == '(')
        my_memcpy(str, str + 1, len);
    if (str[len - 2] == ')')
        str[len - 2] = 0;
    return (str);
}

char *count_len(char *content)
{
    size_t i = 0;
    size_t len = 1;
    char *res = 0;

    if (!content)
        return (0);
    while (content[i++])
        if (content[i] == ' ')
            len++;
    res = my_int_to_str(len);
    free(content);
    return (res);
}

char *array_in_bounds(char *str, int start, int end)
{
    size_t s_idx = 0;
    size_t e_idx = 0;

    while (str[e_idx] && end > 0) {
        e_idx++;
        if (str[e_idx] == ' ')
            end--;
    }
    while (str[s_idx] && start > 0) {
        s_idx++;
        if (str[s_idx] == ' ')
            start--;
    }
    if (str[s_idx] == '(')
        s_idx++;
    if (str[e_idx] == ')')
        e_idx--;
    return (substr(str, s_idx, e_idx));
}
