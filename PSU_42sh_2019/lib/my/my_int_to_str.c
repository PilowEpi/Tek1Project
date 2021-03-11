/*
** EPITECH PROJECT, 2020
** my_int_to_str
** File description:
** Cast int to str
*/

#include <stdlib.h>

#include "my.h"

int get_digit_count(int n)
{
    int len = 0;

    if (n == 0)
        return (1);
    if (n < 0)
        len++;
    while (n != 0){
        len++;
        n /= 10;
    }
    return (len);
}

char *my_int_to_str(int n)
{
    int len = get_digit_count(n);
    int offset = n < 0 ? 1 : 0;
    char *ret = my_malloc(len + offset + 1);

    if (!ret)
        return (0);
    ret[len] = 0;
    if (n < 0){
        ret[0] = '-';
        len--;
    }
    while (len--){
        ret[len + offset] = abs(n % 10) + '0';
        n /= 10;
    }
    return (ret);
}
