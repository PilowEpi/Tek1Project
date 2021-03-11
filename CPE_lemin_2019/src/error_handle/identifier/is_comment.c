/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** is_comment
*/

int is_comment(char *line)
{
    if (line[0] == '\0')
        return (1);
    if (line[0] == '#' && line[1] != '#')
        return (1);
    return (0);
}