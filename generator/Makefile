##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## project's Makefile
##

CC	=	gcc

SRC	=	$(wildcard sources/error_handling/*.c)	\
		$(shell find sources/recursive/ -name "*.c" -type f)	\

TESTS	=	$(shell find ../tests/generator -name "*.c" -type f)

MAIN	=	sources/main.c

NAME	=	generator

OBJ	=	$(SRC:.c=.o)

CPPFLAGS	=	-I../include/ -L../lib/ -lmy -O3

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
	rm -f *.gc*
	rm -f unit_tests

re:	fclean all

unit_tests:
	$(CC) -o unit_tests $(SRC) $(TESTS) $(CPPFLAGS) $(CRITERIONFLAGS)

tests_run:
	./unit_tests

.PHONY: all clean fclean unit_tests tests_run re
