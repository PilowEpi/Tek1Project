/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** get_user_input
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include "my.h"
#include "mysh.h"

char *dup_with_null(char *to_dup, size_t size)
{
    char *result = malloc(size);
    size_t i = 0;

    if (result == NULL)
        return (NULL);
    for (;i != size - 1 && to_dup[i] != '\0' && to_dup[i] != '\n'; i++) {
        result[i] = to_dup[i];
    }
    result[i] = '\0';
    return (result);
}

char *get_user_input(void)
{
    char *input = NULL;
    char *output = NULL;
    size_t len = 0;

    if (isatty(0))
        my_printf("[MiniShell_1]$ ");
    if (getline(&input, &len, stdin) == -1)
        return (NULL);
    output = dup_with_null(input, len);
    if (output == NULL)
        return (NULL);
    free(input);
    return (output);
}