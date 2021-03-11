/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_realloc
*/

#include <stdlib.h>

#include "my.h"

void *my_realloc(void *ptr, int org_size, int dest_size)
{
    void *new_ptr;

    if (ptr == 0)
        return (malloc(dest_size));
    if (dest_size <= org_size)
        return (ptr);
    new_ptr = malloc(dest_size);
    my_memcpy(new_ptr, ptr, org_size);
    free(ptr);
    return (new_ptr);
}

void *my_memcpy(void *dest, const void *src, int size)
{
    char *write = dest;
    char const *read = src;

    while (size--)
        *write++ = *read++;
    return (dest);
}

static void swap_rev(char *a, char *b)
{
    char c = *a;
    *a = *b;
    *b = c;
}

char *my_revstr(char *str)
{
    int length = 0;
    for (; str[length] != '\0'; length++);
    for (int i = 0; i < length / 2; i++) {
        swap_rev(&str[length - i - 1], &str[i]);
    }
    str[length] = '\0';
    return (str);
}
