/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** my_putstr.
*/

#include "matchstick.h"

void my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
}
