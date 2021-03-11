/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** Printers functions
*/

#include <stdarg.h>

#include "my.h"

void print_np(char c, int conf)
{
    int len = get_nbr_length(c, "0123456789", 0);

    c = c > 0 ? c : -c;
    pf_putchar('\\');
    if (c < 64)
        pf_putchar('0');
    if (c < 8)
        pf_putchar('0');
    my_putnbr_base(c, "01234567", len);
}

void put_str_internal(char *s, int mode, int len)
{
    if (!mode){
        for (int i = 0; i < len; i++)
            pf_putchar(s[i]);
        return;
    }
    for (int i = 0; i < len; i++){
        if (s[i] >= 32 && s[i] <= 127)
            pf_putchar(s[i]);
        else
            print_np(s[i], 0);
    }
}

void print_str(va_list *ap, int conf)
{
    char *s = va_arg(*ap, char *);
    int len = (s == 0) ? 6 : my_strlen(s);
    char pr = conf >> 24;

    len = (pr > 0 && len > pr) ? pr : len;
    handle_conf('s', conf, len, 0);
    if (s == 0){
        if (len > 5)
            pf_putstr("(null)");
        else
            len = 0;
        post_conf('s', conf, len, 0);
        return;
    }
    put_str_internal(s, 0, len);
    post_conf('s', conf, len, 0);
    return;
}

void print_str_format(va_list *ap, int conf)
{
    char *s = va_arg(*ap, char *);
    int len = (s == 0) ? 6 : my_strlen(s);
    char pr = conf >> 24;

    len = (pr > 0 && len < pr) ? len : pr;
    handle_conf('s', conf, len, 0);
    if (s == 0){
        if (len > 5)
            pf_putstr("(null)");
        else
            len = 0;
        post_conf('s', conf, len, 0);
        return;
    }
    put_str_internal(s, 1, len);
    post_conf('s', conf, len, 0);
}

void print_nbr(va_list *ap, int conf)
{
    long long int n = get_number(ap, conf, 1);
    int len = get_nbr_length(n, "0123456789", 0);

    handle_conf('d', conf, len, n);
    pf_put_nbr(ABS(n));
    post_conf('d', conf, len, n);
}
