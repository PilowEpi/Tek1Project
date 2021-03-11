/*
** EPITECH PROJECT, 2019
** my_atoi.c
** File description:
** array to int
*/

int my_atoi(char const *src)
{
    int result = 0;

    for (int i = 0; src[i] != '\0'; i++)
        result = (result * 10) + (src[i] - '0');
    return (result);
}
