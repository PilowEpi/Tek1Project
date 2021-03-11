##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC		=		src/list/handling_errors/errors.c		\
				src/list/init_list.c					\
				src/main.c								\
				src/init_game.c							\
				src/list/init_list_bis.c				\
				src/ncurses/init.c						\
				src/ncurses/draw/draw_tetris.c			\
				src/ncurses/init_subwin.c				\
				src/help.c 								\
				src/option/get_option.c 				\
				src/option/set_basic_key.c 				\
				src/option/check_option.c 				\
				src/option/set_opt_key.c 				\
				src/option/set_params_key.c 			\
				src/option/debug_mode.c 				\
				src/list/sort_list.c					\
				src/ncurses/draw/draw_next.c			\
				src/ncurses/play_tetris.c 				\
				src/ncurses/w_score/clock_module.c 		\
				src/ncurses/refresh_game.c 				\
				src/ncurses/w_score/print_score.c		\
				src/ncurses/key/choose_key.c			\
				src/ncurses/key/function_key.c			\
				src/ncurses/delete_line.c				\

OBJ     =       $(SRC:.c=.o)

NAME	=	tetris

NAME_TEST	=	unit_test

CFLAGS  =	-Wall -Wextra -I./include -Llib -l my -lncurses -g

LDFLAGS =       -lcriterion -lgcov --coverage -I./include -Llib -l my -lncurses

all:    $(NAME)

$(NAME):	$(OBJ)
	make -C lib/
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

tests_run : fclean $(OBJ)
	make -C lib/
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
	make -C lib/
	gcc -o $(NAME) $(SRC) $(CFLAGS) -g
	valgrind --leak-check=full --show-leak-kinds=definite --track-origins=yes ./$(NAME) -D

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_TEST)
	make -C lib/ fclean

re:     fclean all
