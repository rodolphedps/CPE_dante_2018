##
## EPITECH PROJECT, 2019
## Makefile generator
## File description:
## generator
##

SRC_DIR	=	src/
TEST_DIR	=	test/

NAME	=	generator

CFLAGS	=	-Wall -Wextra -I ./include

SRC	=	$(SRC_DIR)imperfect_maze.c	\
		$(SRC_DIR)perfect_maze.c	\
		$(SRC_DIR)print.c	\
		$(SRC_DIR)changes.c

SRCS	=	$(SRC) $(SRC_DIR)main.c

SRC_TEST	=	$(TEST_DIR)test_gene.c

TEST_SRC	=	$(SRCS) $(SRC_TEST)

OBJ	=	$(SRCS:.c=.o)

OBJ_TEST	=	$(TEST_SRC:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		rm -f $(OBJ)
		rm -f $(OBJ_TEST)

fclean: clean
		rm -f $(NAME)
		rm -f unit_tests

re: fclean all

test_run:	$(OBJ_TEST)
	$(CC) -o unit_tests $(OBJ_TEST) -lcriterion

.PHONY: all clean fclean re
