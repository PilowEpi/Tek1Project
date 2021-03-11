/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** debug_mode
*/

#include <stddef.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>
#include "tetris.h"
#include "my.h"

char *check_key(int key)
{
    int spec_key[] = {32, 258, 259, 260, 261};
    char *spec_name[] = {"(space)", "^EOB", "^EOA", "^EOD", "^EOC"};

    if (key <= 127 && key != 32)
        return (NULL);
    for (int i = 0; i < 5; i++) {
        if (key == spec_key[i])
            return (spec_name[i]);
    }
    return (NULL);
}

void print_key(options_t *data)
{
    int key[] = {data->key_left, data->key_right, data->key_turn,
        data->key_drop, data->key_quit, data->key_pause};
    char *type[] = {"Left", "Right", "Turn", "Drop", "Quit", "Pause"};
    char *special_key = NULL;

    for (int i = 0; i < 6; i++) {
        special_key = check_key(key[i]);
        if (special_key)
            my_printf("Key %s :  %s\n", type[i], special_key);
        else
            my_printf("Key %s :  %c\n", type[i], key[i]);
    }
}

void print_single_tetris(char **tetris)
{
    for (int i = 0; tetris[i]; i++) {
        if (tetris[i + 1])
            my_printf("%s\n", tetris[i]);
        else
            my_printf("%s", tetris[i]);
    }
}

void print_tetris(game_t *game)
{
    block_t *tmp = game->block;
    int length = 0;

    for (; tmp != NULL; tmp = tmp->next, length++);
    tmp = game->block;
    my_printf("Tetriminos :  %d\n", length);
    for (; tmp != NULL; tmp = tmp->next) {
        my_printf("Tetriminos :  Name %s :  ", tmp->name);
        if (tmp->error == 1) {
            my_printf("Error");
        } else {
            my_printf("Size %d*%d :  ", tmp->x, tmp->y);
            my_printf("Color %d :\n", tmp->color);
            print_single_tetris(tmp->form);
        }
        my_printf("\n");
    }
}

int start_debug_mode(options_t *data, game_t *game)
{
    struct termios config;

    my_printf("*** DEBUG MODE ***\n");
    print_key(data);
    if (data->without_next == 0)
        my_printf("Next :  Yes\n");
    else
        my_printf("Next :  No\n");
    my_printf("Level :  %d\n", data->start_level);
    my_printf("Size :  %d*%d\n", data->map_size_x, data->map_size_y);
    print_tetris(game);
    my_printf("Press any key to start Tetris\n");
    ioctl (0, TCGETS, &config);
    config.c_lflag &= ~(ECHO | ICANON);
    ioctl (0, TCSETS, &config);
    read(0, NULL, 1);
    return (0);
}