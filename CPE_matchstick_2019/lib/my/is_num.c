/*
** EPITECH PROJECT, 2019
** is_num.c
** File description:
** is num or not
*/

int is_num(char c)
{
    if ( c >= '0' && c <= '9')
        return (1);
    return (0);
}
