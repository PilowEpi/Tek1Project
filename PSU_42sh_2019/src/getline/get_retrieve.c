/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** Get and retrieve keys
*/

#include <stdio.h>
#include "my.h"
#include "sh.h"

int get_arrow(char ch, int *cursor, lld_t *str)
{
    if (getchar() != K_SEP)
        return (-1);
    ch = getchar();
    switch (ch) {
        case 'A' :
            return (2);
        case 'B' :
            return (3);
        case 'C' :
            return (go_rigth_cursor(cursor, str));
        case 'D' :
            return (go_left_cursor(cursor, str));
        default :
            return (0);
    }
}

int get_control(char ch, int *cursor, lld_t *str)
{
    if (is_print(ch))
        return (1);
    switch (ch) {
        case 1:
            return (put_cursor(cursor, str));
        default:
            return (0);
    }
}

int get_function(char ch, int *cursor, lld_t *str)
{
    if (ch == K_ESC)
        return (get_arrow(ch, cursor, str));
    else
        return (get_control(ch, cursor, str));
    return (1);
}

int retrive_code(char ch, lld_t *str, int *cursor)
{
    int code = 1;

    code = get_function(ch, cursor, str);
    if (*cursor != 0 && ch == K_SPR) {
        printf("\033[D");
        printf(" ");
        printf("\033[D");
        lld_pop(str, *cursor - 1);
        *cursor = *cursor - 1;
        print_next(cursor, str, 1);
    } else if (code == 1 && ch != K_SPR) {
        lld_insert(str, *cursor, (void *)(u64)ch);
        print_next(cursor, str, 0);
        *cursor = *cursor + 1;
    }
    return (code);
}

int retrive_str(char **line, lld_t *str)
{
    int i = 0;
    int size = lld_len(str);

    *line = malloc(size + 1);
    if (!*line)
        return (-1);
    for (lld_t *mv = str->next; mv; mv = mv->next, i++)
        line[0][i] = (char)(u64)mv->data;
    line[0][size] = '\0';
    lld_free(str);
    return (size);
}
