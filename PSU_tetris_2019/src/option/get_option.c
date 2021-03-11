/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** get_option
*/

#include <stddef.h>
#include "tetris.h"
#include "my.h"

static struct option long_options[] = {
    {"help",    no_argument, 0, 2},
    {"level",  required_argument, 0, 'L'},
    {"key-left",  required_argument, 0, 'l'},
    {"key-rigth", required_argument, 0, 'r' },
    {"key-turn",  required_argument, 0, 't'},
    {"key-drop",    required_argument, 0,  'd' },
    {"key-quit",    required_argument, 0,  'q' },
    {"key-pause",    required_argument, 0,  'p' },
    {"map-size",    required_argument, 0,  3 },
    {"without-next",    no_argument, 0,  'w' },
    {"debug",    no_argument, 0,  'D' },
    {0, 0, 0, 0}
};

int check_option(char c, options_t *data)
{
    int nb_opt = sizeof(opt)/sizeof(opt[0]);
    int returned = 0;

    for (int i = 0; i < nb_opt; i++) {
        if (c == opt[i].name) {
            returned = opt[i].fct_opt(optarg, data);
            break;
        }
    }
    return (returned);
}

int get_option(int ac, char **av, options_t *data)
{
    const char *short_opt = "h2L:l:r:t:d:q:p:1wD";
    char c;
    int returned = 0;

    while ((c = getopt_long(ac, av, short_opt, long_options, NULL)) != -1) {
        returned = check_option(c, data);
        if (returned > 1)
            return (returned);
        else if (returned == 1)
            return (1);
    }
    if (optind < ac)
        return (84);
    else if (check_data(data) == 84)
        return (84);
    return (0);
}