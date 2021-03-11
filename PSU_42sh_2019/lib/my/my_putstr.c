/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** Display a string given as parameter
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    for (; *str != '\0'; str++)
        my_putchar(*str);
    return (0);
}
