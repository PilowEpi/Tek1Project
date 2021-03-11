
/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** init_list_bis.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "tetris.h"
#include "my.h"

void init_collision_tab(block_t *block)
{
    block->collision = malloc(sizeof(int *) * (block->x + 1));
    int a = 0;
    int e = 0;

    for (int i = 0; block->form[i]; i++)
        for (int j = 0; block->form[i][j]; j++)
            block->form[i][j] == '*' ? fill_tab(i, &e, block, j) : 0;
    block->collision[e] = malloc(sizeof(int) * 2);
    block->collision[e][0] = -1;
    block->collision[e++][1] = -1;
}

int strcpy_cat(char *files, char *s, block_t **head, game_t *game)
{
    char *file = malloc(sizeof(char) * 10 * my_strlen(files) + 1);
    int i = 0;
    static int a = 0;

    if (!file)
        return (-1);
    if (files[0] != '.') {
        for (i = 0; s[i] != '\0'; i++)
            file[i] = s[i];
        file[i] = '\0';
        file = my_strcat(file, files);
        game->tetriminos[a++] = my_strdup(file);
    }
    free(file);
    return (0);
}

char *read_file(int fd, char *s)
{
    char *line = NULL;
    struct stat info;

    if (stat(s, &info) == -1) {
        my_printf("%s\n", strerror(errno));
        return (NULL);
    }
    line = malloc(sizeof(char) * info.st_size + 1);
    if (!line)
        return (NULL);
    if (read(fd, line, info.st_size) == -1) {
        my_printf("%s\n", strerror(errno));
        return (NULL);
    }
    line[info.st_size] = '\0';
    return (line);
}

int fill_form(block_t *block, char *line)
{
    int i = 0;
    int a = 0;

    block->form = malloc(sizeof(char *) * (block->y + 1));
    if (!block->form)
        return (-1);
    for (; line[i] != '\n'; i++);
    i += 1;
    for (int j = 0; a < block->y; i++, a++) {
        block->form[a] = malloc(sizeof(char) * block->x + 2);
        if (!block->form[a])
            return (-1);
        for (int e = 0; e < block->x; e++)
            block->form[a][e] = '\0';
        while (line[i] != '\n')
            block->form[a][j++] = line[i++];
        block->form[a][j] = '\0';
        j = 0;
    }
    block->form[a] = NULL;
    return (0);
}

int fill_struct(block_t *block, char *line)
{
    int i = 0;

    for (i = 0; line[i] != ' '; i++)
        block->x += line[i] - 48;
    for (i = i + 1; line[i] != ' '; i++)
        block->y += line[i] - 48;
    for (i = i + 1; line[i] != '\n'; i++)
        block->color += line[i] - 48;
    if (check_nb_line(line, block) == -1 || check_nb_cols(line, block) == -1)
        return (1);
    if (fill_form(block, line) == -1)
        return (-1);
    init_collision_tab(block);
    free(line);
    return (0);
}