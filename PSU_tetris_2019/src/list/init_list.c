/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** init_list.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
#include "tetris.h"
#include <string.h>
#include <errno.h>
#include "my.h"

int init_block(block_t *block, int i, char *s)
{
    int j = 0;

    block->name = malloc(sizeof(char) * my_strlen(s) + 1);
    block->error = 0;
    block->color = 0;
    block->id = i;
    block->x = 0;
    block->y = 0;
    block->next = NULL;
    block->form = NULL;
    if (!block->name)
        return (-1);
    for (i = 0; s[i] != '/'; i++);
    for (i = i + 1; s[i] != '.'; i++)
        block->name[j++] = s[i];
    block->name[j] = '\0';
    return (0);
}

int fill_block(char *s, block_t *block)
{
    int fd = open(s, O_RDONLY);
    char *line = read_file(fd, s);
    int a = 0;

    if (!line || fd == -1)
        return (-1);
    a = fill_struct(block, line);
    if (a == 1)
        return (1);
    if (a == -1)
        return (-1);
    close(fd);
    return (0);
}

block_t *new_block(char *s)
{
    static int i = 0;
    block_t *block = malloc(sizeof(block_t));
    int a = 0;

    if (!block)
        return (NULL);
    if (init_block(block, i, s) == -1)
        return (NULL);
    i++;
    if (check_files(s)) {
        block->error = 1;
        return (block);
    }
    a = fill_block(s, block);
    if (a == 1) {
        block->error = 1;
        return (block);
    }
    return (block);
}

void push_node(block_t **head, block_t *block)
{
    block_t *tmp = (*head);
    if ((*head) == NULL) {
        (*head) = block;
        return;
    }
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = block;
}

int init_list(game_t *game)
{
    block_t **head = &game->block;
    char *s = "tetriminos/";
    DIR *fd = opendir("tetriminos");
    struct dirent *files;
    int a = 0;

    (*head) = NULL;
    if (fd == NULL)
        return (-1);
    while ((files = readdir(fd)) != NULL) {
        if (strcpy_cat(files->d_name, s, head, game) == -1)
            return (-1);
        a++;
    }
    if (a == 2)
        return (1);
    sorted_list(game, fd, head, a);
    return (0);
}