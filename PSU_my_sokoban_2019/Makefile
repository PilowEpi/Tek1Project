##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

SRC 	=	src/stock_file.c \
			src/start_sokoban.c \
			src/fs_open_file.c \
			src/valide_my_map.c \
			src/usage.c \
			src/printw_my_array.c \
			src/find_player.c \
			src/move_player.c \
			src/generic_move.c \
			src/stock_spot.c \
			src/index_of_spot.c \
			src/condition_game.c

SRC_MAIN	=	src/sokoban_main.c

SRC_TEST	=	tests/test_map_verifier.c \
				tests/test_map_verifier_p.c \
				tests/test_map_verifier_x.c \
				tests/test_usage.c \
				tests/test_search_p.c \
				tests/test_lose_game.c \
				tests/test_count_spot.c \
				tests/test_stock_spot.c \
				tests/test_win_game.c \
				tests/test_move_player.c \
				tests/test_move_over_wall.c \
				tests/test_move_x.c \
				tests/test_move_blocked_x.c

OBJ     =       $(SRC:.c=.o) \
				$(SRC_MAIN:.c=.o)

NAME	=	my_sokoban

NAME_TEST	=	unit_test

CFLAGS  =         -Wall -Wextra -lncurses -Iinclude -Llib -l my

LDFLAGS =       -lcriterion -lgcov --coverage

all:    $(NAME)

$(NAME):	lib/libmy.a $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

tests_run :
	make -C lib/
	gcc -o $(NAME_TEST) $(SRC_TEST) $(SRC) $(LDFLAGS) -lncurses -I./include -Llib -lmy
	./$(NAME_TEST)
	gcovr --exclude tests/
	gcovr -b --exclude tests/


clean:
	rm -f $(OBJ)
	find . -type f \(  -name "*~" -o -name "#*#" \) -delete
	find . -type f \( -name "*.gcno" -o -name "*.gcda" \) -delete

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_TEST)
	make -C lib/ fclean

re:     fclean all

lib/libmy.a:
	make -C lib/