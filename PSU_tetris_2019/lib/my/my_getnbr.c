/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** my_getnbr
*/

int my_getnbr(char const *str)
{
    int nb = 0;
    int i = 0;
    int overflow_checker;
    int minus = 1;

    while (str[i] == '+' || str[i] == '-') {
        if (str [i] == '-')
            minus *= -1;
        i++;
    }
    while (str[i] <= '9' && str[i] >= '0') {
        overflow_checker = nb;
        nb = nb * 10 + (str[i] - 48);
        if (nb == 214748364 && str[i + 1] == '8' && minus > 0)
            return (0);
        if (nb / 10 != overflow_checker && nb != -2147483648)
            return (0);
        i++;
    }
    return (nb * minus);
}