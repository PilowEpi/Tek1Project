##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

SRC 	=	src/main.c \
			src/push_core.c \
			src/push_algo.c \
			src/movement_push.c \
			src/elementary_check.c \
			src/buffer_management.c

OBJ     =       $(SRC:.c=.o)

NAME	=	push_swap

CFLAGS  =         -Wall -Wextra -Iinclude -Llib -l my
LDFLAGS =       -lcriterion -lgcov --coverage

all:    $(NAME)

$(NAME):	lib/libmy.a $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

tests_run :
	make -C lib tests_run
	gcovr
	gcovr -b

clean:
	rm -f $(OBJ)
	find . -type f \(  -name "*~" -o -name "#*#" \) -delete
	find . -type f \( -name "*.gcno" -o -name "*.gcda" \) -delete

fclean: clean
	rm -f $(NAME)
	make -C lib/ fclean

re:     fclean all

lib/libmy.a:
	make -C lib/