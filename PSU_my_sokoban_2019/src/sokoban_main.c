/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** sokoban_main
*/

#include "my.h"
#include "sokoban.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int read_file(char const *filepath)
{
    int size;
    struct stat *buf_stat = malloc(sizeof(struct stat));

    if (stat(filepath, buf_stat) == 0)
        size = buf_stat->st_size;
    else
        size = -1;
    free(buf_stat);
    return (size);
}

int open_file(char const *filepath)
{
    int fd = fs_open_file(filepath);
    int size_buffer;
    int condition = 0;

    if (fd == -1)
        return (84);
    size_buffer = read_file(filepath);
    if (size_buffer == -1)
        return (84);
    condition = stock_file(size_buffer, fd);
    if (condition == 84)
        return (84);
    close(fd);
    return (condition);
}

int error_management(int ac)
{
    if (ac != 2) {
        return (84);
    }
    return (0);
}

int main (int ac, char ** av)
{
    int condition;

    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        usage_instructions();
        return (0);
    } else if (error_management(ac) == 0) {
        condition = open_file(av[1]);
        if (condition == 0) {
            return (0);
        } else if (condition == 1) {
            return (1);
        }
        return (84);
    }
    return (84);
}