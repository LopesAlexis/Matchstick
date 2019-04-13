/*
** EPITECH PROJECT, 2018
** my_putnbr.c
** File description:
** my_putnbr.
*/

#include "matchstick.h"

void my_putnbr(int nb)
{
    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
    }
    if (nb >= 10) {
        my_putnbr(nb / 10);
        my_putnbr(nb % 10);
    } else {
        my_putchar(nb + '0');
    }
}
