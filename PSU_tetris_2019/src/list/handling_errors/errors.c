/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** errors.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "tetris.h"
#include "my.h"

int check_nb_line(char *line, block_t *block)
{
    int i = 0;
    int nb = 0;

    for (i = 0; line[i] != '\n'; i++);
    for (i = i + 1; line[i] != '\0'; i++)
        if (line[i] == '\n')
            nb++;
    if (line[i - 1] != '\n')
        nb++;
    if (nb != block->y)
        return (-1);
    return (0);
}

int check_end(char *line, block_t *block, int i, int *nb)
{
    int tmp = 0;

    if (line[i] == '\n' && *nb > block->x) {
        for (tmp = i - 1; line[tmp] == ' '; tmp--, (*nb)--);
        if (*nb > block->x)
            return (-1);
        else
            *nb = 0;
    } else if (line[i] == '\n' && *nb == block->x) {
        *nb = 0;
        return (1);
    }
    if (line[i] == '\n' && *nb < block->x) {
        *nb = 0;
        return (0);
    }
    (*nb)++;
}

int check_nb_cols(char *line, block_t *block)
{
    int i = 0;
    int nb = 0;
    int z = 0;
    int tmp = 0;

    for (i = 0; line[i] != '\n'; i++);
    for (i = i + 1; line[i] != '\0'; i++) {
        tmp = check_end(line, block, i, &nb);
        if (tmp == -1)
            return (-1);
        if (tmp == 1)
            z = 1;
    }
    if (line[i - 1] != '\n' && nb > block->x)
        return (-1);
    if (z == 0 && line[i - 1] == '\n')
        return (-1);
    return (0);
}

int check_buf(char *line)
{
    int i = 0;

    for (i = 0; line[i] != '\n'; i++)
        if ((line[i] < '0' || line[i] > '9') && line[i] != ' ')
            return (1);
    for (i = i + 1; line[i]; i++)
        if (line[i] != '*' && line[i] != ' ' && line[i] != '\n'
        && line[i] != '\0')
            return (1);
    return (0);
}

int check_files(char *s)
{
    int fd = open(s, O_RDONLY);
    struct stat info;
    char line[1000000];
    stat(s, &info);
    read(fd, line, info.st_size);
    line[info.st_size] = '\0';
    if (check_buf(line))
        return (1);
    close (fd);
    return (0);
}