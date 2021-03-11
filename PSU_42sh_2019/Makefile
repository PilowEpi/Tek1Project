##
## EPITECH PROJECT, 2019
## 42sh
## File description:
## Makefile
##

SRC	=	src/shell/main.c				\
		src/shell/shell.c				\
		src/shell/exec.c				\
		src/shell/utils.c				\
		src/shell/path.c				\
		src/shell/inibitor.c			\
		src/builtin/env.c				\
		src/builtin/env_exec.c			\
		src/builtin/env_utils.c			\
		src/builtin/wrapper.c			\
		src/builtin/error.c				\
		src/builtin/builtins.c			\
		src/builtin/wrapper_dirs.c		\
		src/builtin/wrapper_dirs_utils.c\
		src/builtin/wrapper_pushd.c		\
		src/builtin/wrapper_pushd_function.c	\
		src/builtin/wrapper_locale.c	\
		src/builtin/wrapper_history.c	\
		src/builtin/dirs.c				\
		src/parse/utils.c				\
		src/builtin/history.c			\
		src/parse/error.c				\
		src/parse/parse.c				\
		src/parse/connect.c				\
		src/parse/check_connect.c		\
		src/parse/word_tab.c			\
		src/parse/inibited.c			\
		src/preprocess/preprocess.c		\
		src/preprocess/retrieve_vars.c	\
		src/preprocess/star.c			\
		src/preprocess/star_parse.c		\
		src/preprocess/ucp_arg.c		\
		src/preprocess/ucp_second.c		\
		src/preprocess/utils.c			\
		src/getline/my_getline.c		\
		src/getline/get_retrieve.c		\
		src/getline/get_keycode.c 		\
		src/getline/put_cursor.c		\
		src/getline/tabs.c 				\
		src/getline/tabs_exit.c			\
		src/script/config_file.c		\
		src/script/alias.c 				\
		src/script/backticks.c			\
		src/script/backtick.c			\
		src/script/localvar/nts.c		\
		src/script/localvar/local.c		\
		src/script/localvar/getter.c	\
		src/script/localvar/local_3.c	\
		src/script/localvar/local_2.c	\
		src/script/localvar/getter_2.c	\
		src/script/localvar/local_var.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	42sh

CFLAGS	=	-Iinclude -Llib -lmy

all:	$(NAME)

libmy:
	$(MAKE) -C lib/my

$(NAME):libmy $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

debug:
	gcc -g -o $(NAME) $(SRC) $(CFLAGS)

tests_run:
#	$(MAKE) -C tests/
	./unit-tests

clean:	clean_rep
	$(MAKE) -C lib/my clean

clean_rep:
	rm -f $(OBJ)
#	$(MAKE) -C ./tests clean

fclean:	clean_rep
	$(MAKE) -C lib/my fclean
	rm -f lib/my/libmy.a lib/libmy.a
	rm -f $(NAME)
	rm -f vgcore.*
#	$(MAKE) -C ./tests fclean

valgrind: all
	gcc -g -o $(NAME) $(SRC) $(CFLAGS)
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./42sh

run:	$(NAME)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)
	./42sh

re:	fclean all
