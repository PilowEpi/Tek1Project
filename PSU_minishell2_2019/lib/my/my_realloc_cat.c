/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_realloc_cat
*/

#include <stddef.h>
#include <stdlib.h>

int my_strlen_m(char *str)
{
    int length = 0;

    if (str != NULL)
        for (; str[length] != '\0'; length++);
    return (length);
}

char *my_realloc_cat(char *src, char *dest)
{
    int len_src = my_strlen_m(src);
    int len_dest = my_strlen_m(dest);
    int len_result = 0;
    char *result = NULL;

    result = malloc(len_src + len_dest + 1);
    if (result == NULL)
        return (NULL);
    for (int i = 0; i < (len_src + len_dest + 1); i++)
        result[i] = '\0';
    for (int j = 0; j < len_src; j++, len_result++)
        result[len_result] = src[j];
    for (int k = 0; k < len_dest; k++, len_result++)
        result[len_result] = dest[k];
    result[len_result] = '\0';
    return (result);
}