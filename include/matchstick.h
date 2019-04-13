/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** 
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int end_game_msg(int i);

int line_ai(char **arr, char **argv);

int print_even_nbr(char **arr, char **argv, int i);

int end_of_the_game(char **arr, char **argv);

int check_error_matches_buffer(char *buffer);

int check_error_matches(char **arr, char **argv, int matches, int line);

int check_error_line(char *buffer, char **argv, int line);

int check_error(int argc, char **argv);

int my_strlen(char *str);

int nbr_of_pipe(char **arr, char **argv, int line);

int get_lines(char **argv);

int get_matches(char **arr, char **argv, int line);

void my_putnbr(int nb);

int my_strlen(char *str);

void comment(int i, int line, int matches);

int even_nbr(int x);

int my_atoi(char *str);

void my_putstr(char *str);

void my_putchar(char c);

char **updated_board_game(int line, int nb_matches, char **arr, char **argv);

void print_game_board(char **arr, char **argv);

int game_loop(char **arr, char **argv);

char **map(char **arr, char **argv);

char **game_board(char **arr, char **argv);

char **malloc_array(char **arr, char **argv);

