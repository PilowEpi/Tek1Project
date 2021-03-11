/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** parser
*/

#include <stdlib.h>
#include <stdarg.h>

#include "my.h"

int get_flag_index(char const *format, int i)
{
    char *flags = "-+ 0#";

    for (int j = 0; flags[j] != 0; j++){
        if (format[i] == flags[j])
            i = get_flag_index(format, i + 1);
    }
    return (i);
}

int get_width_index(char const *format, int i)
{
    i = get_flag_index(format, i);
    for (; format[i] != 0 && is_num(format[i]); i++);
    if (format[i] == '*')
        i++;
    return (i);
}

int get_precision_index(char const *format, int i)
{
    i = get_width_index(format, i);
    if (format[i] == '.')
        i++;
    for (; format[i] != 0 && is_num(format[i]); i++);
    if (format[i] == '*')
        i++;
    return (i);
}

int get_length_index(char const *format, int i)
{
    char *sizes[] = {"hh", "h", "ll", "l", "L", "z", "j", "t", 0};
    int len = 0;

    i = get_precision_index(format, i);
    for (int j = 0; sizes[j] != 0; j++){
        len = my_strlen(sizes[j]);
        if (my_strncmp(format + i, sizes[j], len) == 0)
            return (i + len);
    }
    return (i);
}

int get_configuration(char const *format, int i, va_list va)
{
    int conf = get_flags(format, i);

    conf |= get_size(format, i) << 8;
    conf |= get_precision(format, i, va) << 16;
    conf |= get_width(format, i, va) << 24;
    return (conf);
}
