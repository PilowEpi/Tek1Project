/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** backstick prosesibng
*/

#include "my.h"

int ucp_backstick(char *str)
{
    int len = my_strlen(str);
    int total = 0;

    for (int i = 0; str[i]; i++)
        str[i] == '`' ? total++ : 0;
    if (total == 2 & str[0] == '`' && str[len-1] == '`')
        return (1);
    return (0);
}
