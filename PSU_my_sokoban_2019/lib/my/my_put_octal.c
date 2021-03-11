/*
** EPITECH PROJECT, 2019
** my_put_octal
** File description:
** my_put_octal
*/

#include "my.h"

void my_put_octal(unsigned int nb)
{
    unsigned int mod;

    if (nb < 8) {
        my_putchar(nb + 48);
    }
    if (nb >= 8) {
        my_put_octal(nb / 8);
        mod = nb % 8;
        my_putchar(mod + 48);
    }
}