/*
** EPITECH PROJECT, 2019
** free_my_array.c
** File description:
** free_my_array
*/

#include "my.h"
#include <stdlib.h>

void free_my_str_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
}

void free_my_int_array(int **array, int line)
{
    for (int i = 0; i < line; i++) {
        free(array[i]);
    }
    free(array);
}