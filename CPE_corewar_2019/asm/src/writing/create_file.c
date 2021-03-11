/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** create_file
*/

#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

#include "my.h"
#include "corewar.h"
#include "op.h"

char *get_filename(char *filename)
{
    int len = my_strlen(filename) + 4;
    char *end = ".cor";
    char *result = malloc(len + 1);

    if (!result)
        return (NULL);
    result[len] = '\0';
    for (int i = 0; i < len - 4; i++)
        result[i] = filename[i];
    for (int i = 0; i < 4; i++)
        result[len - 4 + i] = end[i];
    return (result);
}

int create_comp_file(asm_t *asm_data)
{
    char *filename = get_filename(asm_data->name);
    int fd = 0;

    my_printf("%s\n", filename);
    fd = open(filename, O_RDWR | O_CREAT | O_TRUNC , 0644);
    if (fd < 0)
        return (84);
    write_in_file(asm_data, fd);
    free(filename);
    close(fd);
    return (0);
}
