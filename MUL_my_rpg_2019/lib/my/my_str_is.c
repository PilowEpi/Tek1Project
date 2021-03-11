/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** check strings
*/

#include "my.h"

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        if (!is_alpha(str[i]))
            return (0);
    }
    return (1);
}

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        if (!is_num(str[i]))
            return (0);
    }
    return (1);
}

int my_str_isprintable(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        if (!is_print(str[i]))
            return (0);
    }
    return (1);
}
