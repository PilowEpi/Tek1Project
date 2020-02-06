##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

SRC 	=	src/print_map.c \
			src/create_map.c \
			src/verify_input.c \
			src/get_user_input.c \
			src/game_loop.c \
			src/ask_user.c \
			src/my_ai.c \
			src/ia_utility.c \

SRC_TEST=	tests/test_is_odd.c

MAIN	=	src/main.c

OBJ     =       $(SRC:.c=.o)

NAME	=	matchstick

NAME_TEST = unit_test

CFLAGS  =         -Wall -Wextra -Iinclude -Llib -l my

LDFLAGS =       -lcriterion -lgcov --coverage -Llib -l my -Iinclude

all:    $(NAME)

$(NAME):	lib/libmy.a $(OBJ)
	gcc -o $(NAME) $(OBJ) $(MAIN) $(CFLAGS)

tests_run : fclean $(OBJ)
	make -C lib/
	gcc -o $(NAME_TEST) $(SRC) $(SRC_TEST) $(LDFLAGS)
	./$(NAME_TEST)
	gcovr --exclude ./tests
	gcovr -b --exclude ./tests

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