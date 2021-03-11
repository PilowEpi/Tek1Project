/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** primary file
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "my.h"

void pf_putchar(char c, pf_conf_t *conf)
{
    write(1, &c, 1);
    conf->char_printed += 1;
}

void pf_putstr(char const *s, pf_conf_t *conf)
{
    int len = my_strlen(s);

    write(1, s, len);
    conf->char_printed += len;
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
        free(conf->flags);
        return;
    }
    pr[ty](ap, conf);
    free(conf->flags);
}

int check_format(char const *format, int *i, va_list *ap, pf_conf_t *conf)
{
    if (format[*i] == '%' && format[*i] != '\0'){
        *i += 1;
        print_arg(format, i, ap, conf);
        check_format(format, i, ap, conf);
        return (1);
    }
    return (0);
}

int my_printf(const char *format, ...)
{
    va_list ap;
    pf_conf_t conf;

    conf.char_printed = 0;
    va_start(ap, format);
    for (int i = 0; format[i] != '\0'; i++){
        if (check_format(format, &i, &ap, &conf)){
            i--;
            continue;
        }
        pf_putchar(format[i], &conf);
    }
    va_end(ap);
    return (conf.char_printed);
}
