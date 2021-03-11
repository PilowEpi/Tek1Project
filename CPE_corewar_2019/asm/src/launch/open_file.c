/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** open_file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

#include "my.h"
#include "corewar.h"

int fs_open_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd < 0) {
        my_put_error("Error in function open: No such file or directory.\n");
        return (84);
    }
    return (fd);
}

int length_of_file(int fd_file)
{
    int len = 0;
    int size = 0;
    char buf[20];

    while ((len = read(fd_file, buf, 20)) > 0) {
        size = size + len;
        if (size > 10000)
            return (-1);
    }
    if (lseek(fd_file, 0, SEEK_SET) == -1)
        return (-1);
    return (size);
}

char *read_file(int fd_file)
{
    int len_file = length_of_file(fd_file);
    char buf[1];
    char *map = NULL;

    map = malloc(sizeof(char) * len_file + 1);
    if (!map)
        return (NULL);
    map[len_file] = '\0';
    for (int i = 0; i < len_file; i++) {
        if (lseek(fd_file, i, SEEK_SET) == -1) {
            my_put_error("Lseek failed\n");
            return (NULL);
        }
        read(fd_file, buf, 1);
        map[i] = buf[0];
    }
    return (map);
}

char **open_file(char *path_file)
{
    int fd_file = fs_open_file(path_file);
    char *map = NULL;
    char **map_final = NULL;

    if (fd_file == 84)
        return (NULL);
    map = read_file(fd_file);
    if (!map)
        return (NULL);
    map_final = my_str_to_word_array(map, "\n");
    free(map);
    if (!map_final)
        return (NULL);
    return (map_final);
}
