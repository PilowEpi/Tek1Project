/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** sort_list.c
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

void sorted_list(game_t *game, DIR *fd, block_t **head, int a)
{
    game->tetriminos[a - 2] = NULL;
    game->data.size = a - 2;
    sort_files(game->tetriminos);
    fill_list(game->tetriminos, head);
    closedir(fd);
}

int alphabetic_order(char *s, char *t)
{
    for (int j = 0; s[j]; j++) {
        if (s[j] > t[j])
            return (1);
        if (s[j] < t[j])
            return (0);
    }
    return (0);
}

int is_sorting(char **tab)
{
    for (int i = 0; tab[i + 1]; i++)
        if (alphabetic_order(tab[i], tab[i + 1]))
                return (1);
    return (0);
}

char **sort_files(char **tab)
{
    char *tmpp = NULL;
    while (is_sorting(tab)) {
        for (int i = 0; tab[i + 1]; i++) {
            if (alphabetic_order(tab[i], tab[i + 1])) {
                tmpp = my_strdup(tab[i]);
                tab[i] = my_strdup(tab[i+1]);
                tab[i+1] = my_strdup(tmpp);
            }
        }
    }
    return (tab);
}

void fill_list(char **tab, block_t **head)
{
    for (int i = 0; tab[i]; i++)
        push_node(head, new_block(tab[i]));
    free_my_str_array(tab);
}