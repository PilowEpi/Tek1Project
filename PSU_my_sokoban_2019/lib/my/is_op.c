/*
** EPITECH PROJECT, 2019
** is_op.c
** File description:
** is op or not
*/

#include "my.h"

int is_op(char c)
{
    if ( c == '+' || c == '-' ||
        c == '*' || c == '/' ||
        c == '%' || c == '(' ||
        c == ')')
        return (1);
    return (0);
}
