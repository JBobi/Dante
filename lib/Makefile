##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## project's Makefile
##

SRC	=	$(shell find ./ -name "*.c" -type f)

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
