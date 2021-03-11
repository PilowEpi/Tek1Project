/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** Display the passed number to stdout
*/

#include "my.h"

void pf_put_nbr(long long int nb, pf_conf_t *conf)
{
    int magnitude = 1;
    long long int nb_copy = nb;
    if (nb < 0) {
        pf_putchar('-', conf);
        if (nb == -2147483648) {
            pf_putchar('2', conf);
            nb = -147483648;
        }
        nb *= -1;
        nb_copy = nb;
    }
    while (nb_copy > 9) {
        magnitude *= 10;
        nb_copy /= 10;
    }
    while (magnitude > 0) {
        pf_putchar((nb / magnitude) % 10 + 48, conf);
        magnitude /= 10;
    }
}
