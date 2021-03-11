/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** main
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

#include "my.h"
#include "corewar.h"

void help_usage(void)
{
    my_printf("USAGE\n");
    my_printf("./asm file_name[.s]\n");
    my_printf("DESCRIPTION\n");
    my_printf("file_name file in assembly language to be ");
    my_printf("converted into file_name.cor, an\n");
    my_printf("executable in the Virtual Machine.\n");
}

int main(int ac, char **av)
{
    if (ac == 2 && !my_strcmp(av[1], "-h")) {
        help_usage();
        return (0);
    } else if (ac == 2) {
        return (launch_asm(av[1]));
    }
    my_put_error("Missing filepath, try ./asm -h\n");
    return (84);
}