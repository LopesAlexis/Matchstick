/*
** EPITECH PROJECT, 2019
** size.c
** File description:
** size.
*/

#include "matchstick.h"

int nbr_of_pipe(char **arr, char **argv, int line)
{
    int pipe = 0;

    for (int i = 0; i <= 2 * my_atoi(argv[1]) - 1; i++) {
        if (arr[line][i] == '|')
            pipe = pipe + 1;
    }
    return (pipe);
}

int end_of_the_game(char **arr, char **argv)
{
    for (int l = 0; l <= my_atoi(argv[1]) + 1; l++) {
        for (int c = 0; c <= 2 * my_atoi(argv[1]); c++) {
            if (arr[l][c] == '|')
                return (1);
        }
    }
    return (0);
}

int line_ai(char **arr, char **argv)
{
    for (int l = 0; l <= my_atoi(argv[1]) + 1; l++) {
        for (int c = 0; c <= 2 * my_atoi(argv[1]); c++) {
            if (arr[l][c] == '|')
                return (l);
        }
    }
}

int end_game_msg(int i)
{
    if (even_nbr(i) == 0) {
        my_putstr("You lost, too bad...\n");
        return (2);
    } else if (even_nbr(i) == 1) {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        return (1);
    }
}
