##
## EPITECH PROJECT, 2019
## name
## File description:
## Makefile
##

SRC     =	$(shell find . ../lib/my/ -name '*.c')

OBJ     =	$(SRC:.c=.o)

CC	=	gcc

CPPFLAGS	=	-I include -g3

NAME    =	matchstick

FLAG	=	-W -Wall -Werror -Wextra  -g3 -O3

all:    $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -f $(shell find $(SOURCEDIR) -name '*.o')
	rm -f $(shell find $(SOURCEDIR) -name '*~')
	rm -f $(shell find $(SOURCEDIR) -name '*.gc*')

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re


