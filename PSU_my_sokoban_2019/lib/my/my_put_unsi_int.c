/*
** EPITECH PROJECT, 2019
** my_put_usi_int.c
** File description:
** my_put_usi_int
*/

#include "my.h"

void my_put_unsi_int(unsigned int nb)
{
    unsigned int mod;

    if (nb < 10) {
        my_putchar(nb + 48);
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        mod = nb % 10;
        my_putchar(mod + 48);
    }
}