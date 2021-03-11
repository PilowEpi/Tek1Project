/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** Ucp second file
*/

#include "my.h"

int ucp_varname(char *str)
{
    for (int i = 0; i < my_strlen(str); i++)
        if (!is_alpha(str[i]) && !is_num(str[i]))
            return (0);
    if (!is_alpha(str[0]))
        return (0);
    return (1);
}

int ucp_seperator(char *str)
{
    if (*str != ' ')
        return (0);
    for (; *str == ' '; str++);
    return (!*str);
}

int ucp_arguments(char *str)
{
    int f = 0;

    for (int i = 0; str[i]; i++){
        str[i] == '`' ? f ^= 4 :
        str[i] == '\'' && !(f & 6) ? f ^= 1 :
        str[i] == '\"' && !(f & 5) ? f ^= 2 : 0;
    }
    return (!f);
}

int ucp_any(char *str)
{
    return (1);
}

int ucp_len(char *str)
{
    return (ucp(str, "$#*", ucp_varname)
        || ucp(str, "$#* *", ucp_varname, ucp_any));
}
