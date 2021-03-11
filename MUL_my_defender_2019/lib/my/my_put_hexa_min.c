/*
** EPITECH PROJECT, 2019
** my_put_hexa.c
** File description:
** my_put_hexa_min
*/

#include "my.h"

void my_put_hexa_min(unsigned int nb)
{
    unsigned int mod;

    if (nb < 16) {
        if (nb < 10) {
            my_putchar(nb + 48);
        } else if (nb >= 10){
            my_putchar(nb + 87);
        }
    }
    if (nb >= 16) {
        my_put_hexa_min(nb / 16);
        mod = nb % 16;
        if (mod < 10) {
            my_putchar(mod + 48);
        } else if (mod >= 10){
            my_putchar(mod + 87);
        }
    }
}

void my_put_hexa_ptr(long int nb)
{
    long int mod;

    if (nb < 16) {
        if (nb < 10) {
            my_putchar(nb + 48);
        } else if (nb >= 10){
            my_putchar(nb + 87);
        }
    }
    if (nb >= 16) {
        my_put_hexa_ptr(nb / 16);
        mod = nb % 16;
        if (mod < 10) {
            my_putchar(mod + 48);
        } else if (mod >= 10){
            my_putchar(mod + 87);
        }
    }
}