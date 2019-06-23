##
## EPITECH PROJECT, 2019
## Makefile solver
## File description:
## solver
##

SRC_DIR	=	src/

NAME	=	solver

SRC	=	$(SRC_DIR)main.c	\
		$(SRC_DIR)size.c	\
		$(SRC_DIR)solver.c	\
		$(SRC_DIR)check_buffer.c	\

CFLAGS	=	-g3 -Wall -Wextra -Werror -I ./include

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
