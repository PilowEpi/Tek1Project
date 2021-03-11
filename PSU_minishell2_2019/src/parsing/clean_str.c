/*
** EPITECH PROJECT, 2020
** src
** File description:
** clean_str
*/

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

void clean_start(char *str)
{
    int i = 0;
    int j = 0;

    if (str[0] == ' ' || str[0] == '\t') {
        j++;
        for (;str[j] != '\0'; i++, j++) {
            str[i] = str[j];
        }
        str[i] = '\0';
    }
}

void clean_end(char *str)
{
    int len = my_strlen(str) - 1;

    if (len == -1)
        len = 0;
    if (str[len] == ' ' || str[len] == '\t') {
        str[len] = '\0';
    }
}

int verify_quote(int s_q, int d_q)
{
    if (s_q != 0) {
        my_put_error("Unmatched '\''.\n");
        return (84);
    } else if (d_q != 0) {
        my_put_error("Unmatched '\"'.\n");
        return (84);
    }
    return (0);
}

int clean_str(char *str)
{
    int d_q = 0;
    int s_q = 0;
    int space = 0;
    int i = 0;
    int j = 0;

    for (;str[i] != '\0' && str[j] != '\0'; i++, j++) {
        d_q += (str[j] == '\"' && !s_q)? 1 : 0;
        s_q += (str[j] == '\'' && !d_q)? 1 : 0;
        d_q = (d_q == 2)? 0 : d_q;
        s_q = (s_q == 2)? 0 : s_q;
        if (space && (str[j] == ' ' || str[j] == '\t') && !d_q && !s_q)
            i--;
        space = (str[j] == ' ' || str[j] == '\t')? 1 : 0;
        str[i] = str[j];
    }
    str[i] = '\0';
    clean_start(str);
    clean_end(str);
    return (verify_quote(s_q, d_q));
}