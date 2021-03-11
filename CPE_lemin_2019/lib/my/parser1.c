/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** parser
*/

#include "my.h"

int get_flags(char const *format, int i)
{
    char *flags = "-+ 0#";
    int ret = 0;

    for (int j = 0; flags[j] != 0; j++){
        if (format[i] == flags[j]){
            ret |= 1 << (j + 1);
            i++;
            j = -1;
        }
    }
}

char get_size(char const *format, int i)
{
    char *sizes[] = {"hh", "h", "ll", "l", "L", "z", "j", "t", 0};
    int len = 0;

    i = get_precision_index(format, i);
    for (int j = 0; sizes[j] != 0; j++){
        len = my_strlen(sizes[j]);
        if (my_strncmp(format + i, sizes[j], len) == 0)
            return (j);
    }
    return (-1);
}

char get_type(char const *format, int i)
{
    char *types = "sdicSbpxuf%noX";

    i = get_length_index(format, i);
    for (int j = 0; types[j] != 0; j++){
        if (format[i] == types[j])
            return (j);
    }
    return (-1);
}

char get_width(char const *format, int i, va_list va)
{
    char width = -1;
    int w_index = get_width_index(format, i);
    int f_index = get_flag_index(format, i);

    if (f_index != w_index && is_num(format[f_index]))
        width = my_getnbr(format + f_index);
    if (*(format + f_index) == '*')
        width = va_arg(va, int);
    return (width);
}

char get_precision(char const *format, int i, va_list va)
{
    char precision = -1;
    int w_index = get_width_index(format, i);
    int p_index = get_precision_index(format, i);

    if (w_index != p_index && is_num(format[w_index + 1]))
        precision = my_getnbr(format + w_index + 1);
    if (*(format + w_index + 1) == '*')
        precision = va_arg(va, int);
    return (precision);
}
