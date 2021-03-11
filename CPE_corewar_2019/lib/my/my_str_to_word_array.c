/*
** EPITECH PROJECT, 2019
** my_str_to_word_array.c
** File description:
** my_str_to_word_array
*/
#include "my.h"
#include <stddef.h>
#include <stdlib.h>

int is_separator(char c, char *sep)
{
    for (int i = 0; i < my_strlen(sep); i++) {
        if (sep[i] == c)
            return (1);
    }
    return (0);
}

int count_line(char const *str, char *sep)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        if (is_separator(str[i], sep) == 1) {
            count++;
        }
        i++;
    }
    count += 1;
    return (count);
}

char **fill_my_array(char const *str, char **array, char *sep)
{
    int k = 0;

    if (array == NULL)
        return (NULL);
    for (int i = 0; array[i] != NULL; i++) {
        for (int j = 0; (is_separator(str[k], sep) != 1) &&
            (str[k] != '\0'); j++) {
            array[i][j] = str[k];
            k++;
        }
        if (str[k] != '\0')
            k++;
    }
    return (array);
}

char **my_str_to_word_array(char const *str, char *sep)
{
    int line = (str == NULL)? 0 : count_line(str, sep);
    int counted_char = 0;
    int j = 0;
    char **array = malloc(sizeof(char *) * (line + 1));

    array[line] = NULL;
    for (int i = 0; i < line && array != NULL; i++) {
        while (str[j] != '\0' && is_separator(str[j], sep) != 1) {
            j++;
            counted_char++;
        }
        j++;
        array[i] = malloc(sizeof(char) * (counted_char + 1));
        if (array[i] == NULL)
            return (NULL);
        array[i][counted_char] = '\0';
        counted_char = 0;
    }
    array = fill_my_array(str, array, sep);
    return (array);
}