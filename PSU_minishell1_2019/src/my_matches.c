/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_matches
*/

int my_matches(char *str, char *cmp)
{
    int all = 0;
    int index = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        all = (cmp[index] == '*') ? 1 : 0;
        if (!all && str[i] == cmp[index])
            index++;
        else if (all && str[i])
            return (0);
        else
            return (1);
    }
    return (0);
}
