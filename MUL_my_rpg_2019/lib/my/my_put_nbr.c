/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** Display the passed number to stdout
*/

#include "my.h"

void pf_put_nbr(long long int nb)
{
    int magnitude = 1;
    long long int nb_copy = nb;
    if (nb < 0) {
        pf_putchar('-');
        if (nb == -2147483648) {
            pf_putchar('2');
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
        pf_putchar((nb / magnitude) % 10 + 48);
        magnitude /= 10;
    }
}

int my_put_nbr(int nb)
{
    int magnitude = 1;
    int nb_copy = nb;
    if (nb < 0) {
        my_putchar('-');
        if (nb == -2147483648) {
            my_putchar('2');
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
        my_putchar((nb / magnitude) % 10 + 48);
        magnitude /= 10;
    }
}

static int get_display_length(unsigned long long int nbr, char const *base)
{
    int i = 0;
    int len = 0;

    for (; base[len] != '\0'; len++);
    while (nbr >= len){
        nbr /= len;
        i++;
    }
    return (i);
}

void my_putnbr_base(unsigned long long int nbr, char const *base,
    int disp_len)
{
    int len = 0;
    int i = 0;
    int checker;
    char mem_display[disp_len];

    for (; base[len] != '\0'; len++);
    while (nbr >= len){
        checker = nbr % len;
        nbr /= len;
        mem_display[i++] = base[checker];
    }
    mem_display[i] = base[nbr % len];
    for (int j = disp_len - 1; j != -1; j--)
        pf_putchar(mem_display[j]);
}

void my_put_unsigned_nbr(unsigned long long int nb)
{
    long long int magnitude = 1;
    unsigned long long int nb_copy = nb;

    while (nb_copy > 9) {
        magnitude *= 10;
        nb_copy /= 10;
    }
    while (magnitude > 0) {
        pf_putchar((nb / magnitude) % 10 + 48);
        magnitude /= 10;
    }
}
