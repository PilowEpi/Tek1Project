/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** in_quote
*/

int in_quote(char *str, int len)
{
    int d_q = 0;
    int s_q = 0;

    for (int i = 0; i < len && str[i] != '\0'; i++) {
        d_q += (str[i] == '\"' && !s_q)? 1 : 0;
        s_q += (str[i] == '\'' && !d_q)? 1 : 0;
        d_q = (d_q == 2)? 0 : d_q;
        s_q = (s_q == 2)? 0 : s_q;
    }
    if (d_q || s_q)
        return (1);
    return (0);
}