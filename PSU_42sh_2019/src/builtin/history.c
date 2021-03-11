/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** builtins history
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#include "sh.h"
#include "my.h"

char *get_hourminute(void)
{
    time_t raw_time;
    struct tm *timeinfo;
    int hour;
    int minute;
    char *hour_s, *minute_s, *str_time;

    time(&raw_time);
    timeinfo = localtime(&raw_time);
    hour = timeinfo->tm_hour;
    minute = timeinfo->tm_min;
    str_time = malloc(6);
    sprintf(str_time, "%02i:%02i", hour, minute);
    return (str_time);
}

void show_history(shell_t *sh)
{
    int y = 1;
    hist_t *h = NULL;

    if (sh->history->data == 0)
        return;
    for (u64 i = (u64) sh->history->data -1; i; i--) {
        h = lld_read(sh->history, i);
        printf("  %d\t%s\t%s\n", y++, h->time, h->cmd);
    }
}

int add_history(shell_t *sh, char *cmds)
{
    char *time = get_hourminute();
    char *cmd = my_strdup(cmds);
    hist_t *new_h = malloc(sizeof(hist_t));
    char *history_line = get_lvar(sh->l_var, "history");
    int h_c;

    luis_decrypt(cmd);
    new_h->time = time;
    new_h->cmd = cmd;
    lld_insert(sh->history, 0, new_h);
    if (!history_line || !my_getnbr(history_line))
        return (0);
    h_c = my_getnbr(history_line);
    while (h_c > (u64) sh->history->data) {
        lld_pop(sh->history, (int) ((u64) sh->history->data - 1));
    }
    return (0);
}
