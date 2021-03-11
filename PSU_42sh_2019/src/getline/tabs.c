/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** tabs for auto complete
*/

#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "sh.h"

void lld_sort_dest(lld_t *result);

int complete_mod(lld_t *str, int cursor)
{
    if (cursor <= 0 || str->data == 0)
        return (1);
    for (; cursor > 0 && lld_read(str, cursor-1) != (void *)' '; cursor--);
    for (; cursor > 0 && lld_read(str, cursor-1) == (void *)' '; cursor--);
    if (cursor != 0)
        return (1);
    return (0);
}

lld_t *fill_lld(int *cursor, lld_t *str, shell_t *sh)
{
    struct dirent *dirent;
    DIR *dir;
    lld_t *posi = lld_init();
    char **path = get_paths(sh->env);
    if (complete_mod(str, *cursor)) {
        dir = opendir(".");
        while (dirent = readdir(dir))
            lld_insert(posi, 0, my_strdup(dirent->d_name));
        closedir(dir);
    } else
        for (int i = 0; path[i]; i++){
            if (!(dir = opendir(path[i]))) continue;
            while (dirent = readdir(dir))
                lld_insert(posi, 0, my_strdup(dirent->d_name));
            closedir(dir);
        }
    for (int i = 0; path[i]; i++)
        free(path[i]);
    free(path);
    return (posi);
}

int strcmp_first(char *s1, char *s2)
{
    int i = 0;

    for (; s1[i] && s1[i] == s2[i]; i++);
    return (!s1[i]);
}

int condition_str(lld_t *str, char *strs, int cursor, int *curs)
{
    char buf[1024];
    int i = 0;
    lld_t *result = (lld_t *)lld_pop(str, 0);

    if ((u64)result->data >= 42){
        printf("\nDisplay all %i possibilities? (y or n)\n", result->data);
        if (read(0, buf, 1024) && buf[0] == 'y')
            for (lld_t *mv = result->next; mv; mv = mv->next)
                printf("%s\n", mv->data);
    } else if ((u64)result->data == 1){
        for (; strs[cursor+i] && RES_NEXT[i] == strs[cursor+i]; i++);
        for (; RES_NEXT[i]; curs[0]++, i++){
            lld_insert(str, curs[0], (void *)(u64)RES_NEXT[i]);
            write(1, &((char *)result->next->data)[i], 1);
        }
        return (1);
    } else
        for (lld_t *mv = result->next; mv; mv = mv->next)
            printf("%s\n", mv->data);
    return (0);
}

void complete_str(shell_t *sh, lld_t *str, int *curs)
{
    lld_t *posi = fill_lld(curs, str, sh);
    int len = 0;
    char *strs = malloc((u64)str->data+1);
    int cursor = *curs;
    lld_t *result = lld_init();

    !strs ? exit (84) : (strs[cursor] = 0);
    strs[(u64)str->data] = 0;
    for (lld_t *mv = str->next; mv; mv = mv->next, len++)
        strs[len] = (char)(u64)mv->data;
    for (; strs[cursor] != ' ' && cursor > 0; cursor--);
    strs[cursor] == ' ' ? cursor++ : 0;
    for (lld_t *mv = posi->next; mv; mv = mv->next)
        if (strcmp_first(strs+cursor, mv->data))
            lld_insert(result, 0, mv->data);
    lld_sort_dest(result);
    lld_insert(str, 0, result);
    if (!result->data || condition_str(str, strs, cursor, curs))
        return;
    exit_completion(strs, posi, result, str);
}
