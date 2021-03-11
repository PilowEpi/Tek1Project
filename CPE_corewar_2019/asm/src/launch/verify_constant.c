/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** verify_constant
*/

#include "my.h"
#include "corewar.h"
#include "op.h"

int check_same(char *to_check, int i, int j)
{
    if (i != j && to_check[i] == to_check[j])
        return (1);
    return (0);
}

int verify_char(char *to_check)
{
    int error = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 4; j > 0; j--) {
            error += check_same(to_check, i, j);
        }
        if (error)
            return (84);
    }
    return (0);
}

int verify_const_nbr(void)
{
    if (PROG_NAME_LENGTH <= 0)
        return (84);
    else if (COMMENT_LENGTH <= 0)
        return (84);
    return (0);
}

int verify_constant(void)
{
    char *label = LABEL_CHARS;
    char constant[] = {COMMENT_CHAR, LABEL_CHAR, DIRECT_CHAR, SEPARATOR_CHAR};

    if (verify_char(label) || verify_char(constant) || verify_const_nbr()) {
        my_put_error("op.h : Error in constant\n");
        return (84);
    } else if (!my_strcmp(NAME_CMD_STRING, COMMENT_CMD_STRING)) {
        my_put_error("NAMES / COMMENT : Error same name\n");
        return (84);
    }
    return (0);
}