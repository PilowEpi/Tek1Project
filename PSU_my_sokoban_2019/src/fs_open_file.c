/*
** EPITECH PROJECT, 2019
** fs_open_file.c
** File description:
** open file
*/

#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include <unistd.h>

int fs_open_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *failure = "syntax error\n";

    if (fd == -1) {
        write(1, failure, my_strlen(failure));
        return (-1);
    }
    return (fd);
}