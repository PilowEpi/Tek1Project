/*
** EPITECH PROJECT, 2019
** my_put_hexa.c
** File description:
** my_put_hexa_maj
*/

#include "my.h"

void my_put_hexa_maj(unsigned int nb)
{
    unsigned int mod;

    if (nb < 16) {
        if (nb < 10) {
            my_putchar(nb + 48);
        } else if (nb >= 10){
            my_putchar(nb + 55);
        }
    }
    if (nb >= 16) {
        my_put_hexa_maj(nb / 16);
        mod = nb % 16;
        if (mod < 10) {
            my_putchar(mod + 48);
        } else if (mod >= 10){
            my_putchar(mod + 55);
        }
    }
}