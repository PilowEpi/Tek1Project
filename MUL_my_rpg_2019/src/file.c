/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** File handling
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "rpg.h"

int get_filesize(char *path)
{
    int fd = 0;
    int size = 0;
    int size_read = 1;
    char buf[16];

    if (!path)
        return (-1);
    fd = open(path, O_RDONLY);
    while (fd != -1 && size_read != 0) {
        size_read = read(fd, buf, 16);
        size += size_read;
    }
    close(fd);
    return (size);
}

char *read_file(char *path)
{
    int size = get_filesize(path);
    char *buf = 0;
    int fd;

    if (!path || size == -1)
        return (0);
    buf = malloc(size + 1);
    buf[size] = 0;
    fd = open(path, O_RDONLY);
    if (fd != -1)
        read(fd, buf, size);
    close(fd);
    return (buf);
}
