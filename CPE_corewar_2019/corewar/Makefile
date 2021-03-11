##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC		=		src/main.c			\
				src/base_convert.c

OBJ     =       $(SRC:.c=.o)

NAME	=	corewar

NAME_TEST	=	unit_test

CFLAGS  =	-I../include -L../lib -l my

LDFLAGS =       -lcriterion -lgcov --coverage --I../include -L../lib -l my

all:    $(NAME)

$(NAME):	$(OBJ)
	make -C ../lib/
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

test_run : fclean $(OBJ)
	CFLAGS += -Wall -Wextra
	make -C ../lib/
	gcc -o $(NAME_TEST) $(SRC) $(LDFLAGS)
	./$(NAME_TEST)
	gcovr --exclude tests/
	gcovr -b --exclude tests/

clean:
	rm -f $(OBJ)
	find . -type f \(  -name "*~" -o -name "#*#" \) -delete
	find . -type f \( -name "*.gcno" -o -name "*.gcda" \) -delete

valgrind: fclean
	clear
	make -C ../lib/
	gcc -o $(NAME) $(SRC) $(CFLAGS) -g
	valgrind --leak-check=full --show-leak-kinds=definite --track-origins=yes ./$(NAME)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_TEST)
	make -C ../lib/ fclean

re:     fclean all
