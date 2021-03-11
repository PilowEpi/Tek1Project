/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** printers function
*/

#include <stdio.h>

#include "my.h"

void print_char(va_list *ap, int conf)
{
    int c = va_arg(*ap, int);

    handle_conf('c', conf, 1, 0);
    pf_putchar(c);
    post_conf('c', conf, 1, 0);
}

void print_percent(va_list *ap, int conf)
{
    pf_putchar('%');
}

void print_memory(va_list *ap, int conf)
{
    int *address = va_arg(*ap, int *);

    *address = 42;
}

void print_octal(va_list *ap, int conf)
{
    unsigned long long int n = get_number(ap, conf, 0);
    int len = get_nbr_length(n, "01234567", 1);

    handle_conf('o', conf, len, n);
    my_putnbr_base(n, "01234567", len);
    post_conf('o', conf, len, n);
}

void print_hexa_maj(va_list *ap, int conf)
{
    unsigned long long int n = get_number(ap, conf, 0);
    int len = get_nbr_length(n, "0123456789ABCDEF", 1);

    handle_conf('X', conf, len, n);
    my_putnbr_base(n, "0123456789ABCDEF", len);
    post_conf('X', conf, len, n);
}
