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
    write(conf->fd, &c, 1);
    conf->char_printed += 1;
}

void pf_putstr(char const *s, pf_conf_t *conf)
{
    int len = my_strlen(s);

    write(conf->fd, s, len);
    conf->char_printed += len;
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
    conf.fd = 1;
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

int my_dprintf(int fd, const char *format, ...)
{
    va_list ap;
    pf_conf_t conf;

    conf.char_printed = 0;
    conf.fd = fd;
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
