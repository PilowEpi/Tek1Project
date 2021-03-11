/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** stock_file
*/

#include "sokoban.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

char *read_and_stock(int size_buffer, int fd)
{
    char *buffer = malloc(sizeof(char) * (size_buffer + 1));

    buffer[size_buffer] = '\0';
    if (buffer == 0)
        return (NULL);
    read(fd, buffer, size_buffer);
    return (buffer);
}

int stock_file(int size_buffer, int fd)
{
    char *buffer = read_and_stock(size_buffer, fd);
    int condition = 0;

    if (is_invalid_map(buffer) == 84) {
        free(buffer);
        return (84);
    }
    condition = start_game(buffer);
    if (condition == 84) {
        free(buffer);
        return (84);
    }
    free(buffer);
    return (condition);
}