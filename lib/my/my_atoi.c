/*
** EPITECH PROJECT, 2018
** my_atoi.c
** File description:
** my_atoi.
*/

#include "matchstick.h"

int my_atoi(char *str)
{
    int i = 0;
    int nb = 0;

    while (str[i] != '\0') {
        if (str[i] >= 48 && str[i] <= 57) {
            nb = nb * 10;
            nb = nb + str[i] - 48;
        }
        i++;
    }
    if (str[0] == 45)
        nb = nb - nb * 2;
    return (nb);
}
