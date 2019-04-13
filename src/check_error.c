/*
** EPITECH PROJECT, 2019
** check_error.c
** File description:
** check_error.
*/

#include "matchstick.h"

int check_error_matches_buffer(char *buffer)
{
    for (int i = 0; i <= my_strlen(buffer) - 1; i++) {
        if (buffer[i] < 48 || buffer[i] > 57 && buffer[i] != 45) {
            my_putstr("Error: invalid input (positive number expected)\n");
            return (1);
        } else if (buffer[i] == 45) {
            my_putstr("Error: you have to remove at least one match\n");
            return (1);
        }
    }
    return (0);
}

int check_error_matches(char **arr, char **argv, int matches, int line)
{
    int p = nbr_of_pipe(arr, argv, line);

    if (matches > p) {
        my_putstr("Error: not enough matches on this line\n");
        return (1);
    } else if (matches > my_atoi(argv[2])) {
        my_putstr("Error: you cannot remove more than ");
        my_putnbr(my_atoi(argv[2]));
        my_putstr(" matches per turn\n");
        return (1);
    }
    return (0);
}

int check_error_line(char *buffer, char **argv, int line)
{
    for (int i = 0; i <= my_strlen(buffer) - 1; i++) {
        if (buffer[i] < 48 || buffer[i] > 57) {
            my_putstr("Error: invalid input (positive number expected)\n");
            return (1);
        } else if (line > my_atoi(argv[1]) || line <= 0) {
            my_putstr("Error: this line is out of range\n");
            return (1);
        }
    }
    return (0);
}

int check_error(int argc, char **argv)
{
    int d = 0;

    if (argc != 3)
        return (7);
    if (my_atoi(argv[1]) < 2 || my_atoi(argv[1]) > 99)
        return (7);
    for (int c = 1; c <= 2; c++) {
        for (int i = 0; argv[c][i] != '\0'; i++) {
            if (argv[c][i] < 48 || argv[c][i] > 57 || argv[c][0] == 48)
                return (7);
        }
    }
    return (0);
}
