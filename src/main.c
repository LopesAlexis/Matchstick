/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "matchstick.h"

int game_loop(char **arr, char **argv)
{
    int i = 0;
    int line = 100000;
    int matches = 100000;

    while (1) {
        if (end_of_the_game(arr, argv) == 0)
            line = 0;
        else if (even_nbr(i) == 1) {
            print_even_nbr(arr, argv, i);
            line = -1;
        } else {
            print_even_nbr(arr, argv, i);
            line = 100000;
            matches = 100000;
        }
        while (line > my_atoi(argv[1])) {
            line = get_lines(argv);
            if (line == 0)
                return (7);
            if (line != 100000) {
                matches = get_matches(arr, argv, line);
                if (matches == 0)
                    return (7);
                else if (matches == 100000)
                    line = 100000;
            }
        }
        if (line == 0) {
            i++;
            return (i);
        } else if (line == -1)
            i++;
        else {
            comment(i, line, matches);
            updated_board_game(line, matches, arr, argv);
            print_game_board(arr, argv);
            line = 100000;
            matches = 100000;
            i++;
        }
    }
}

char **map(char **arr, char **argv)
{
    int cc = (2 * (my_atoi(argv[1]) - 1)) / 2;
    int ccc = (2 * (my_atoi(argv[1]) - 1)) / 2 + 2;

    for (int v = 1; v <= my_atoi(argv[1]); v++) {
        for (int c = 1; c <= 2 * my_atoi(argv[1]) - 1; c++) {
            if (c <= cc)
                arr[v][c] = ' ';
            else if (c >= ccc)
                arr[v][c] = ' ';
            else
                arr[v][c] = '|';
        }
        cc--;
        ccc++;
    }
    return (arr);
}

char **game_board(char **arr, char **argv)
{
    for (int v = 0; v <= my_atoi(argv[1]) + 1; v++) {
        for (int c = 0; c <= 2 * my_atoi(argv[1]); c++) {
            if (v == 0 || c == 0 || v == my_atoi(argv[1]) + 1
                || c == 2 * my_atoi(argv[1]))
                arr[v][c]  = '*';
            else
                arr[v][c] = ' ';
        }
    }
    return (arr);
}

char **malloc_array(char **arr, char **argv)
{
    for (int i = 0; i <= my_atoi(argv[1]) + 1; i++)
        arr[i] = malloc(sizeof(char) * 2 * my_atoi(argv[1]) + 1);
    return (arr);
}

int main(int argc, char **argv)
{
    char **arr;
    int i;

    if (check_error(argc, argv) == 7) {
        my_putstr("error\n");
        return (84);
    }
    arr = malloc(sizeof(char *) * my_atoi(argv[1]) + 2);
    arr = malloc_array(arr, argv);
    arr = game_board(arr, argv);
    arr = map(arr, argv);
    print_game_board(arr, argv);
    i = game_loop(arr, argv);
    if (i == 7)
        return (0);
    i = end_game_msg(i);
    if (i == 1)
        return (1);
    else if (i == 2)
        return (2);
}
