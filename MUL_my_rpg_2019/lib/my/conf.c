/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** Configuration handling
*/

#include "my.h"
//    char *flags = "-+ 0#";

int is_signed(char type)
{
    if (type == 'd' || type == 'i' || type == 'f' ||
        type == 'f' || type == 'F' || type == 'e' ||
        type == 'E' || type == 'g' || type == 'G')
        return (1);
    return (0);
}

void handle_number(char type, int conf, int nb)
{
    if (!is_signed(type))
        return;
    if (nb < 0)
        return (pf_putchar('-'));
    if (conf & F_PLS)
        pf_putchar('+');
    else if (conf & F_SPC)
        pf_putchar(' ');
}

int handle_alt(char type, int conf, int nb, int printing)
{
    if (!(conf & F_HSH))
        return (0);
    switch (type){
    case 'o':
        if (printing)
            pf_putchar('0');
        return (1);
    case 'x':
        if (printing)
            pf_putstr("0x");
        return (2);
    case 'X':
        if (printing)
            pf_putstr("0X");
        return (2);
    }
    return (0);
}

void handle_conf(char type, int conf, int size, int nb)
{
    int offset = ((conf & F_PLS) | (conf & F_SPC)) & nb > 0 | nb < 0;
    int padding = (conf >> 24) - size - offset;
    int zeros = 0;

    if (type == '%')
        return;
    padding -= handle_alt(type, conf, nb, 1);
    if ((conf >> 16) & 0xFF > 0 && ((conf & F_MIN) | (conf & F_NUL))
        && is_numtype(type))
        padding -= (zeros = ((conf >> 16) & 0xFF) - size);
    else if (conf >> 24 > 0 && (conf & F_NUL) && is_numtype(type))
        padding -= (zeros = (conf >> 24) - size);
    if (!(conf & F_MIN))
        for (int i = 0; i < padding; i++)
            pf_putchar(' ');
    handle_number(type, conf, nb);
    for (int i = 0; i < zeros; i++)
        pf_putchar('0');
}

void post_conf(char type, int conf, int size, int nb)
{
    char print = ' ';
    int offset = ((conf & F_PLS) | (conf & F_SPC)) & nb > 0 | nb < 0;
    int padding = (conf >> 24) - size - offset;

    if (!(conf & F_MIN))
        return;
    padding -= handle_alt(type, conf, nb, 0);
    if ((conf >> 16) & 0xFF > 0 && ((conf & F_MIN) | (conf & F_NUL))
        && is_numtype(type))
        padding -= ((conf >> 16) & 0xFF) - size;
    else if (conf >> 24 > 0 && (conf & F_NUL) && is_numtype(type))
        padding -= conf << 24 - size;
    for (int i = 0; i < padding; i++)
        pf_putchar(print);
}
