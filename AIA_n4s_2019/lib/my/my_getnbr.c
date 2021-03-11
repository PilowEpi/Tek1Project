/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** Get the first number found in string
*/

int is_recognized(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    if (c == '-' || c == '+')
        return (1);
    return (0);
}

int my_getnbr(char const *str)
{
    int res = 0;
    int end = 1;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '8' && res == 214748364 && end != -1)
            return (0);
        if (str[i] >= '0' && str[i] <= '9')
            res = 10 * res + str[i] - '0';
        if (str[i] == '-' && res == 0)
            end *= -1;
        if (str[i] == '+' && res == 0)
            end = 1;
        if (is_recognized(str[i]) == 0)
            break;
        if (res < 0 && res != -2147483648)
            return (0);
    }
    if (res != -2147483648)
        res *= end;
    return (res);
}
