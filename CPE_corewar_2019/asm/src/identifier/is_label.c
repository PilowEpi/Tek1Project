/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** is_label
*/

#include "op.h"
#include "my.h"

int is_label_char(char c)
{
    char *label_chars = LABEL_CHARS;
    int size_label_chars = my_strlen(label_chars);

    for (int i = 0; i < size_label_chars; i++) {
        if (label_chars[i] == c)
            return (1);
    }
    return (0);
}

int is_label(char *str)
{
    int len = my_strlen(str);

    for (int i = 0; str[i]; i++) {
        if (is_label_char(str[i])) {
            continue;
        } else if (i + 1 == len && str[i] == LABEL_CHAR) {
            return (-1);
        } else {
            break;
        }
    }
    return (0);
}