##
## EPITECH PROJECT, 2019
## makefile dante
## File description:
## dante
##

SOLV	=	./solver/
GENE	=	./generator/

all:
	make -C $(SOLV)
	make -C $(GENE)

clean:
	make clean -C $(SOLV)
	make clean -C $(GENE)

fclean:	clean
	make fclean -C $(SOLV)
	make fclean -C $(GENE)

re:	fclean all

.PHONY: all clean fclean re