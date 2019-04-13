/*
** EPITECH PROJECT, 2019
** even_nbr.c
** File description:
** even_nbr.
*/

#include "matchstick.h"

int get_lines(char **argv)
{
    int c;
    int line;
    size_t input;
    size_t bufsize = 20;
    char *buffer = malloc(sizeof(char) * bufsize);

    my_putstr("Line: ");
    input = getline(&buffer, &bufsize, stdin);
    if (input == -1)
        return (0);
    line = my_atoi(buffer);
    if (buffer[0] == 45 || buffer[0] == '\n') {
        my_putstr("Error: this line is out of range\n");
        c = 1;
    } else
        c = check_error_line(buffer, argv, line);
    if (c == 1)
        line = 100000;
    return (line);
}

int get_matches(char **arr, char **argv, int line)
{
    int c;
    int matches;
    size_t input;
    size_t bufsize = 20;
    char *buffer = malloc(sizeof(char) * bufsize);

    my_putstr("Matches: ");
    input = getline(&buffer, &bufsize, stdin);
    if (input == -1)
        return (0);
    matches = my_atoi(buffer);
    if (buffer[0] == 45 || buffer[0] == '\n' || buffer[0] == 48) {
        my_putstr("Error: You have to remove at least one match\n");
        c = 1;
    } else {
        c = check_error_matches(arr, argv, matches, line);
        if (c == 0)
            c = check_error_matches_buffer(buffer);
    }
    if (c == 1) {
        matches = 100000;
    }
    return (matches);
}

void comment(int i, int line, int matches)
{
    if (even_nbr(i) == 0) {
        my_putstr("Player removed ");
        my_putnbr(matches);
        my_putstr(" match(es) from line ");
        my_putnbr(line);
        my_putchar('\n');
    } else {
        my_putstr("AI removed ");
        my_putnbr(matches);
        my_putstr(" match(es) from line ");
        my_putnbr(line);
        my_putchar('\n');
    }
}

int print_even_nbr(char **arr, char **argv, int i)
{
    int line = line_ai(arr, argv);
    int matches = 1;

    if (i%2 == 0) {
        my_putstr("\nYour turn:\n");
    } else {
        my_putstr("\nAI's turn...\n");
        comment(i, line, matches);
        updated_board_game(line, matches, arr, argv);
        print_game_board(arr, argv);
    }
}

int even_nbr(int x)
{
    if (x%2 == 0)
        return (0);
    else
        return (1);
}
