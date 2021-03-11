/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** main
*/

#include "my.h"
#include "corewar.h"
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int print_line(char *line)
{
    if (line == NULL)
        return (1);
    for (int i = 0; line[i]; i += 2) {
        my_printf("%c%c", line[i], line[i + 1]);
        if (i != 30)
            my_printf(" ");
        if (i == 14)
            my_printf(" ");
    }
    my_printf("\n");
    return (0);
}

int line_complete(char *line, char *hex)
{
    int last = my_strlen(line);

    line[last] = hex[0];
    line[last + 1] = hex[1];
    line[last + 2] = '\0';
    free(hex);
    if (my_strlen(line) < 32) {
        return (0);
    }
    print_line(line);
    free(line);
    line = malloc(sizeof(char) * 32);
    if (line == NULL)
        exit(84);
    return (1);
}

int main(int ac, char **av)
{
    FILE *fp = fopen(av[1], "rb");
    char *buff = malloc(sizeof(char) * 32);
    char *c_converted;

    if (fp == NULL || buff == NULL)
        return (84);
    buff[0] = '\0';
    for (int c = fgetc(fp); c != EOF; c = fgetc(fp)) {
        c_converted = my_convert(c, 16, 1);
        line_complete(buff, c_converted);
    }
    print_line(buff);
    free(buff);
    fclose(fp);
    return (0);
}