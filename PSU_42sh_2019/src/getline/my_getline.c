/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** my_getline
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "sh.h"

void print_next(int *cursor, lld_t *str, int spaces)
{
    int j = 0;
    lld_t *mv = str->next;

    for (int i = 0; mv != NULL && i != *cursor; mv = mv->next)
        i++;
    if (isatty(0)) {
        for (; mv != NULL; mv = mv->next, j++) {
            printf("%c", (char)(u64)mv->data);
        }
    }
    for (int i = 0; i < spaces; i++, j++)
        printf(" ");
    for (; j != 0; j--)
        printf("\033[D");
}

int go_left_cursor(int *cursor, lld_t *str)
{
    if (*cursor != 0) {
        *cursor = *cursor - 1;
        printf("\033[D");
    }
    return (4);
}

int go_rigth_cursor(int *cursor, lld_t *str)
{
    int size = lld_len(str);

    if (*cursor != size) {
        *cursor = *cursor + 1;
        printf("\033[C");
        print_next(cursor, str, 1);
    }
    return (5);
}

int char_entry(char ch, shell_t *sh, int *cursor, lld_t *str)
{
    if (isatty(0) && ch == '\t') {
        complete_str(sh, str, cursor);
        return (-1);
    } else if (ch <= 0 || ch == K_ENT) {
        return (-1);
    }
    return (0);
}

int my_getline(char **line, shell_t *sh)
{
    lld_t *str = lld_init();
    int code = 0;
    int ch;
    int cursor = 0;

    do {
        ch = get_keycode();
        if (ch == 4 || ch == -1)
            return (-1);
        else if (char_entry(ch, sh, &cursor, str) == -1)
            continue;
        code = retrive_code(ch, str, &cursor);
        if (isatty(0) && code == 1)
            printf("%c", ch);
    } while (ch != K_ENT);
    printf("\n");
    return (retrive_str(line, str));
}
