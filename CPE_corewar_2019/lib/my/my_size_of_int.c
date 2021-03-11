/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_size_of_nbr
*/

#include "my.h"

int my_size_of_int(int value)
{
    int result = 0;

    if (value < 0)
        value *= -1;
    result++;
    for (int i = 0; i <= 10; i++) {
        if (value < 10) {
            i = 10;
        } else {
            value = value / 10;
            result++;
        }
    }
    return (result);
}