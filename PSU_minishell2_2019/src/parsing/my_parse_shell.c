/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_parse_shell
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "mysh.h"

void parse_string(char *str)
{
    int d_q = 0;
    int s_q = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        d_q += (str[i] == '\"' && !s_q)? 1 : 0;
        s_q += (str[i] == '\'' && !d_q)? 1 : 0;
        d_q = (d_q == 2)? 0 : d_q;
        s_q = (s_q == 2)? 0 : s_q;
        if ((str[i] == ' ' || str[i] == '\t' ) && !d_q && !s_q)
            str[i] = -100;
    }
}

int count_args(char *str)
{
    int args = 0;
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] == -100)
            args++;
    }
    if (i != 0)
        args++;
    return (args);
}

int get_length(char *str)
{
    int i = 0;
    int length = 0;

    if (str[0] == '\'' || str[0] == '\"')
        length -= 2;
    while (str[i] != '\0' && str[i] != -100) {
        length++;
        i++;
    }
    return (length);
}

char **fill_parsing(char *str, int nb_args)
{
    char **result = malloc(sizeof(char *) * (nb_args + 1));
    int size = 0;
    int index = 0;

    if (result == NULL)
        return (NULL);
    for (int i = 0; i < nb_args; i++) {
        size = get_length(&str[index]);
        result[i] = malloc(sizeof(char) * (size + 1));
        if (result[i] == NULL)
            return (NULL);
        for (int j = 0; j < size; j++, index++) {
            index += (!j && (str[index] == '\'' || str[index] == '\"'))? 1 : 0;
            result[i][j] = str[index];
        }
        result[i][size] = '\0';
        index++;
    }
    result[nb_args] = NULL;
    return (result);
}

char **my_parse_shell(char *to_parse)
{
    int nb_args = 0;
    char **result = NULL;

    parse_string(to_parse);
    nb_args = count_args(to_parse);
    if (nb_args == 0 && to_parse[0] == '\0')
        return (NULL);
    result = fill_parsing(to_parse, nb_args);
    return (result);
}