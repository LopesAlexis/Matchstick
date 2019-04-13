/*
** EPITECH PROJECT, 2019
** print_game.c
** File description:
** print_game.
*/

#include "matchstick.h"

void print_game_board(char **arr, char **argv)
{
    for (int v = 0; v <= my_atoi(argv[1]) + 1; v++) {
        for (int c = 0; c <= 2 * my_atoi(argv[1]); c++) {
            my_putchar(arr[v][c]);
        }
        my_putchar('\n');
    }
}

char **updated_board_game(int line, int nb_matches, char **arr, char **argv)
{
    int max_matches = my_atoi(argv[2]);
    int matches = 0;

    for (int i = 1; i <= 2 * my_atoi(argv[1]) - 1; i++) {
        if (arr[line][i] == '|')
            matches = matches + 1;
    }
    if (matches < nb_matches)
        return (arr);
    for (int c = 2 * my_atoi(argv[1]) - 1; c >= 1; c--) {
        if (nb_matches == 0) {
            return (arr);
        } else if (arr[line][c] == '|') {
            arr[line][c] = ' ';
            nb_matches = nb_matches - 1;
        }
    }
    return (arr);
}
