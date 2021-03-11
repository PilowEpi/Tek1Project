/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** my_memset
*/

int my_memset(char *str, int len)
{
    if (!str)
        return (0);
    for (int i = 0; i < len; i++) {
        str[i] = '\0';
    }
    return (0);
}