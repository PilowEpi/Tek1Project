/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_strcmp
*/

int my_strcmp(char const *str1, char const *str2)
{
    int i = 0;

    while (str1[i] == str2[i] && str1[i] && str2[i]) {
        i++;
    }
    return (str1[i] - str2[i]);
}