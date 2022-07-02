##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## project's Makefile
##

CC	=	gcc

SRC	=	$(wildcard sources/calc_heuristic/*.c)	\
		$(wildcard sources/get_maze/*.c)	\
		$(wildcard sources/error_handling/*.c)	\
		$(wildcard sources/create_stmap/*.c)	\
		$(wildcard sources/main_function/*.c)	\
		$(wildcard sources/linked_lists/*.c)	\

TESTS	=	$(shell find ../tests/solver/ -name "*.c" -type f)

MAIN	=	sources/main.c

NAME	=	solver

OBJ	=	$(SRC:.c=.o)

CPPFLAGS	=	-I../include/ -L../lib/ -lmy

CFLAGS	=	-Werror -Wall -pedantic

CRITERIONFLAGS	=	--coverage -lcriterion

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ../lib/
	$(CC) -o $(NAME) $(MAIN) $(OBJ) $(CPPFLAGS)

clean:
	make clean -C ../lib/
	rm -f $(OBJ)

fclean:	clean
	make fclean -C ../lib/
	rm -f $(NAME)
	rm -rf *.gc*
	rm -rf unit_tests

re:	fclean all

unit_tests:
	$(CC) -o unit_tests $(SRC) $(TESTS) $(CPPFLAGS) $(CRITERIONFLAGS)

tests_run:
	./unit_tests

.PHONY: all clean fclean unit_tests tests_run re
