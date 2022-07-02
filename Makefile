##
## EPITECH PROJECT, 2022
## dante
## File description:
## Makefile
##

NAME	=	compile

all:	$(NAME)

$(NAME):
	make -C lib/
	make -C solver/
	make -C generator/

clean:
	make clean -C lib/
	make clean -C solver/
	make clean -C generator/

fclean:
	make fclean -C lib/
	make fclean -C solver/
	make fclean -C generator/

re: fclean all

unit_tests:	fclean
	make -C lib/
	make unit_tests -C generator/
	make unit_tests -C solver/

tests_run:	unit_tests
	make tests_run -C generator/
	make tests_run -C solver/

.PHONY:	all clean fclean unit_tests tests_run re
