/*
** EPITECH PROJECT, 2019
** my_put_bin.c
** File description:
** my_put_bin
*/

#include "my.h"

void my_put_bin(unsigned int nb)
{
    unsigned int mod;

    if (nb < 2) {
        my_putchar(nb + 48);
    }
    if (nb >= 2) {
        my_put_bin(nb / 2);
        mod = nb % 2;
        my_putchar(mod + 48);
    }
}