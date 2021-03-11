##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC		=		src/main_shell.c 						\
				src/builtins/my_exit.c					\
				src/builtins/my_cd_list.c				\
				src/builtins/my_setenv_list.c			\
				src/builtins/shell_command.c			\
				src/builtins/my_unset_list.c			\
				src/env/init/init_env.c					\
				src/env/init/print_env.c				\
				src/env/manage/transform_env.c			\
				src/env/manage/get_value_of_env.c		\
				src/env/manage/get_index_of_env.c		\
				src/interaction/my_exe.c				\
				src/interaction/print_status.c			\
				src/interaction/task_interpreter.c		\
				src/parsing/clean_str.c					\
				src/parsing/concat_exe.c				\
				src/parsing/my_matches.c				\
				src/parsing/my_parse_shell.c			\
				src/parsing/preload_task.c				\
				src/parsing/space_add.c					\
				src/parsing/in_quote.c					\
				src/parsing/my_memset.c					\
				src/parsing/task/identifier_task.c		\
				src/parsing/task/verify_task.c			\
				src/user/shell_loop.c					\
				src/user/get_user_input.c				\
				src/interaction/exe/simple_exe.c		\
				src/interaction/exe/pipe.c				\
				src/interaction/exe/redir.c 			\

OBJ     =       $(SRC:.c=.o)

NAME	=	mysh

NAME_TEST	=	unit_test

CFLAGS  =	-Wall -Wextra -I./include -Llib -l my

LDFLAGS =       -lcriterion -lgcov --coverage -I./include -Llib -l my

all:    $(NAME)

$(NAME):	$(OBJ)
	make -C lib/
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

test_run : fclean $(OBJ)
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
