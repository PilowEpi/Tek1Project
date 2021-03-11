##
## EPITECH PROJECT, 2019
## Lemin
## File description:
## Makefile
##

SRC	=	src/main.c									\
		src/error_handle/start_error.c				\
		src/error_handle/get_command.c				\
		src/error_handle/function/check_start.c		\
		src/error_handle/identifier/is_room.c		\
		src/error_handle/identifier/is_pipe.c		\
		src/error_handle/identifier/is_comment.c	\
		src/error_handle/identifier/is_command.c	\
		src/parsing/add_room.c						\
		src/parsing/add_pipe.c						\
		src/lemin/start_lemin.c						\
		src/lemin/add_in_data.c						\
		src/solve/solve.c							\
		src/solve/path.c							\
		src/error_handle/remove_comment.c			\
		src/error_handle/function/check_coord.c		\

#		src/error_handle/function/check_ant.c		\
#		src/error_handle/function/check_end.c		\
#		src/error_handle/function/check_no_pipe.c   \
#		src/error_handle/function/check_no_room.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	lem_in

CFLAGS	=	-Iinclude -Llib -lmy

all:
	$(MAKE) -C lib/my --no-print-directory
	$(MAKE) -C lib/my clean --no-print-directory
	$(MAKE) $(NAME) --no-print-directory

$(NAME):$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

debug:
	gcc -g -o $(NAME) $(SRC) $(CFLAGS)

tests_run:
	$(MAKE) -C tests/ --no-print-directory
	./unit-tests

clean:
	rm -f $(OBJ)
	$(MAKE) -C ./tests clean --no-print-directory

fclean:	clean
	rm -f lib/my/libmy.a lib/libmy.a
	rm -f $(NAME)
	$(MAKE) -C ./tests fclean --no-print-directory

valgrind: fclean
	clear
	make -C lib/my
	gcc -o $(NAME) $(SRC) $(CFLAGS) -g
	valgrind --leak-check=full --show-leak-kinds=definite --track-origins=yes ./$(NAME) < test_files/anthill_ok

re:	fclean all
