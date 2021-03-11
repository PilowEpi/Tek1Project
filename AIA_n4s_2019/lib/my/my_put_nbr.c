/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** Display the passed number to stdout
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    int magnitude = 1;
    int nb_copy = nb;
    if (nb < 0) {
        my_putchar('-');
        if (nb == -2147483648) {
            my_putchar('2');
            nb = -147483648;
        }
        nb *= -1;
        nb_copy = nb;
    }
    while (nb_copy > 9) {
        magnitude *= 10;
        nb_copy /= 10;
    }
    while (magnitude > 0) {
        my_putchar((nb / magnitude) % 10 + 48);
        magnitude /= 10;
    }
}
