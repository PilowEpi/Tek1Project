/*
** EPITECH PROJECT, 2019
** my_put_nbr.c
** File description:
** for lib
*/

#include "my.h"

void my_put_nbr(int nb)
{
    int mod;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb < 10) {
        my_putchar(nb + 48);
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        mod = nb % 10;
        my_putchar(mod + 48);
    }
}
