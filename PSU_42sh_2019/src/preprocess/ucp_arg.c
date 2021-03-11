/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** ucp for arguments
*/

#include "my.h"

int ucp_set(char *str)
{
    return (ucp(str, "$?*", ucp_varname)
        || ucp(str, "$?* *", ucp_varname, ucp_any));
}

int ucp_array(char *str)
{
    return (ucp(str, "$*[*]", ucp_varname, my_str_isnum)
        || ucp(str, "$*[*] *", ucp_varname, my_str_isnum, ucp_any)
        || ucp(str, "$*[*-*]", ucp_varname, my_str_isnum, my_str_isnum)
        || ucp(str, "$*[*-*] *", ucp_varname, my_str_isnum, my_str_isnum,
        ucp_any)
        || ucp(str, "${*[*]}", ucp_varname, my_str_isnum)
        || ucp(str, "${*[*]}*", ucp_varname, my_str_isnum, ucp_any)
        || ucp(str, "${*[*-*]}", ucp_varname, my_str_isnum, my_str_isnum)
        || ucp(str, "${*[*-*]}*", ucp_varname, my_str_isnum, my_str_isnum,
        ucp_any));
}

int ucp_zero(char *str)
{
    return (!my_strcmp(str, "$0"));
}

int ucp_argv(char *str)
{
    return (!my_strcmp(str, "$argv") | !my_strcmp(str, "$*"));
}

int ucp_var(char *str)
{
    return (ucp(str, "${*}*", ucp_varname, ucp_any)
        || ucp(str, "$* *", ucp_varname, ucp_any)
        || ucp(str, "${*}", ucp_varname)
        || ucp(str, "$*", ucp_varname));
}
