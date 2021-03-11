/*
** EPITECH PROJECT, 2019
** my_str_to_word_array.c
** File description:
** my_str_to_word_array
*/
#include "my.h"
#include <stddef.h>
#include <stdlib.h>

int is_separator(char c)
{
    switch (c) {
        case '\n' :
        case '\t' :
            return (1);
    }
    return (0);
}

int count_line(char const *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        if (is_separator(str[i]) == 1) {
            count++;
        }
        i++;
    }
    return (count);
}

char **fill_my_array(char const *str, char **array)
{
    int k = 0;

    if (array == NULL)
        return (NULL);
    for (int i = 0; array[i] != NULL; i++) {
        for (int j = 0; (is_separator(str[k]) != 1) && (str[k] != '\0'); j++) {
            array[i][j] = str[k];
            k++;
        }
        if (str[k] != '\0')
            k++;
    }
    return (array);
}

char **my_str_to_word_array(char const *str)
{
    int line = count_line(str);
    int counted_char = 0;
    int j = 0;
    char **array = malloc(sizeof(char *) * (line + 1));

    array[line] = NULL;
    for (int i = 0; i < line && array != NULL; i++) {
        while (is_separator(str[j]) != 1) {
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
    array = fill_my_array(str, array);
    return (array);
}