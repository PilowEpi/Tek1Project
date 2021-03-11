/*
** EPITECH PROJECT, 2019
** put_double
** File description:
** Main file
*/

#include "my.h"

#include <stdarg.h>

double get_double_mag(double a)
{
    double mag = 1;

    while (a > 10 * mag)
        mag *= 10;
    return (mag);
}

int float_equal(double a, double b)
{
    int ab = ABS(a - b);

    if (b == 1.f)
        return (a > b);
    return (ab < 0.01);
}

double float_mod(double a, double n)
{
    double mag = get_double_mag(a);

    while (a > n || float_equal(a, n)){
        if (a > mag * n || float_equal(a, mag * n))
            a -= mag * n;
        else
            mag /= 10;
    }
    return (ABS(a));
}

void put_double(double a, double precision, int conf)
{
    double float_p = float_mod(a, 1) * 10;
    double int_p = (a - float_mod(a, 1));
    double mag = get_double_mag(a);
    int round;

    while (mag > 0.1){
        pf_putchar(float_mod(int_p / mag, 10) + 0x30);
        mag /= 10;
    }
    if (precision <= 0)
        return;
    pf_putchar('.');
    while (precision-- > 1){
        pf_putchar(float_mod(float_p, 10) + 0x30);
        float_p *= 10;
    }
    round = (int) float_mod(float_p, 10);
    if (float_mod(float_p * 10, 10) > 4)
        round += (round < 9 ? 1 : -10);
    pf_putchar(round + 0x30);
}

void print_double(va_list *ap, int conf)
{
    double res = va_arg(*ap, double);
    int precision = 6;
    char pr = (conf >> 16) & 0xFF;

    if (pr != -1)
        precision = pr;
    put_double(res, precision, conf);
}
