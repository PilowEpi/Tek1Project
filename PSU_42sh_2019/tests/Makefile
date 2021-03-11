##
## EPITECH PROJECT, 2019
## test
## File description:
## Makefile
##

SRC	=	test.c

OBJ	=	$(SRC:.c=.o)

NAME	=	unit-tests

CFLAGS	=	-I../include -L../lib/my -lmy --coverage -lcriterion

all:
	$(MAKE) -C ../lib/my --no-print-directory
	$(MAKE) -C ../lib/my clean --no-print-directory
	$(MAKE) $(NAME) --no-print-directory

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)
	cp $(NAME) ../$(NAME)

clean:
	rm -f $(OBJ)
	find .. -name "*.gcno" -delete -o -name "*.gcda" -delete

fclean:	clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re:	fclean all
