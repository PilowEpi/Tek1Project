/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** get_user_input
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "my.h"
#include "matchstick.h"

char *dup_with_null(char *to_dup, size_t size)
{
    char *result = malloc(size + 1);

    if (result == NULL)
        return (NULL);
    result[size] = '\0';
    for (size_t i = 0; i < size; i++) {
        result[i] = to_dup[i];
    }
    return (result);
}

char *get_user_input(void)
{
    char *input = NULL;
    char *output = NULL;
    size_t len = 0;
    if (getline(&input, &len, stdin) == -1)
        return (NULL);
    output = dup_with_null(input, len);
    if (output == NULL)
        return (NULL);
    free(input);
    return (output);
}