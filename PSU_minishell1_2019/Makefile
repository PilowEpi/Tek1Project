##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC		=		src/main_shell.c \
				src/get_user_input.c \
				src/init_env.c \
				src/print_env.c \
				src/shell_loop.c \
				src/my_exit.c \
				src/task_interpreter.c \
				src/clean_str.c \
				src/shell_command.c \
				src/my_unset_list.c \
				src/get_index_of_env.c \
				src/my_setenv_list.c \
				src/my_cd_list.c \
				src/get_value_of_env.c \
				src/my_parse_shell.c \
				src/my_matches.c \
				src/my_exe.c \
				src/transform_env.c \
				src/concat_exe.c \
				src/print_status.c

OBJ     =       $(SRC:.c=.o)

NAME	=	mysh

NAME_TEST	=	unit_test

CFLAGS  =	-Wall -Wextra -I./include -Llib -l my

LDFLAGS =       -lcriterion -lgcov --coverage -I./include -Llib -l my

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
	valgrind --leak-check=full --show-leak-kinds=definite --track-origins=yes ./$(NAME)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_TEST)
	make -C lib/ fclean

re:     fclean all
