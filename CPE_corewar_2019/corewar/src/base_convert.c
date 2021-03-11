/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** base_convert
*/

#include "my.h"
#include <stdlib.h>

char *my_revstr(char *str)
{
    int last_i = my_strlen(str) - 1;
    int first_i;
    char swap;

    for (first_i = 0; first_i < last_i;
    first_i++, last_i--) {
        swap = str[last_i];
        str[last_i] = str[first_i];
        str[first_i] = swap;
    }
    return (str);
}

char *convert_rec(long long nb, int base, int lowercase, char *dest)
{
    char *alpha = "0123456789abcdefghijklmnopqrstuvwxyz";
    long long modul = nb % base;
    long long result = (nb - modul) / base;
    int last_char_index;

    if (!lowercase)
        alpha = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (last_char_index = 0; dest[last_char_index]; last_char_index++);
    dest[last_char_index] = alpha[modul];
    if (result > 0)
        return (convert_rec(result, base, lowercase, dest));
    else
        return (dest);
}

char *my_convert(int nb, int base, int lowercase)
{
    char *dest = malloc(sizeof(char) * 3);

    if (dest == NULL || nb > 255)
        exit(84);
    dest[0] = '\0';
    my_revstr(convert_rec(nb, base, lowercase, dest));
    if (dest[1] == '\0') {
        dest[1] = dest[0];
        dest[0] = '0';
        dest[2] = '\0';
    }
    return (dest);
}
