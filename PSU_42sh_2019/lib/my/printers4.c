/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** printers
*/

#include <stdarg.h>
#include <stdlib.h>

#include "my.h"

void print_hexa_maj(va_list *ap, pf_conf_t *conf)
{
    unsigned long long int n = get_number(ap, conf, 0);
    int len = get_nbr_length(n, "0123456789ABCDEF", 1);

    handle_conf('X', conf, len, n);
    my_putnbr_base(n, "0123456789ABCDEF", len, conf);
    post_conf('X', conf, len, n);
}

void print_arg(char const *format, int *i, va_list *ap, pf_conf_t *conf)
{
    void (*pr[])(va_list *, pf_conf_t *) = {print_str, print_nbr, print_nbr,
        print_char, print_str_format, print_binary, print_pointer, print_hexa,
        print_unsigned, print_double, print_percent, print_errno, print_memory,
        print_octal, print_hexa_maj};
    int ty = get_type(format, *i);

    get_configuration(format, *i, conf);
    *i = get_length_index(format, *i) + 1;
    if (ty < 0){
        my_free(conf->flags);
        return;
    }
    pr[ty](ap, conf);
    my_free(conf->flags);
}
