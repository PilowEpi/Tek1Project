/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** get_keycode
*/

#include <stdio.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "sh.h"

int get_keycode(void)
{
    struct termios old_termios;
    struct termios new_termios;
    int ch;

    tcgetattr(STDIN_FILENO, &old_termios );
    new_termios = old_termios;
    new_termios.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &old_termios);
    return (ch);
}

int *get_len_term(void)
{
    struct winsize win;
    static int len[2];

    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &win) == -1)
        return (NULL);
    len[0] = win.ws_row;
    len[1] = win.ws_col;
    return (len);
}
