##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC		=		src/main.c								\
				src/op.c								\
				src/launch/open_file.c					\
				src/launch/launch_asm.c					\
				src/launch/verify_constant.c			\
				src/launch/clean_memory.c				\
				src/parsing/get_name.c					\
				src/parsing/parse_data.c				\
				src/parsing/fill_command.c				\
				src/parsing/node_utils.c				\
				src/writing/create_file.c				\
				src/writing/write_in_file.c				\
				src/writing/write_byte_code.c			\
				src/identifier/is_reg.c					\
				src/identifier/is_label.c				\
				src/identifier/is_direct.c				\
				src/identifier/is_indirect.c			\
				src/identifier/is_index.c				\
				src/verifier/verify_data.c				\
				src/verifier/get_type.c					\
				src/verifier/verify_syntax.c			\
				src/verifier/print_line_error.c			\
				src/verifier/verify_name.c				\
				src/verifier/verify_args.c				\
				src/verifier/verify_comment.c   		\
				src/code/byte_sums.c					\
				src/code/get_command_id.c				\
				src/code/calculate_params.c				\
				src/code/calculate_args.c				\
				src/code/write_type.c					\

OBJ     =       $(SRC:.c=.o)

NAME	=	asm

NAME_TEST	=	unit_test

CFLAGS  =	-Wall -Wextra -I../include -L../lib -l my

LDFLAGS =       -lcriterion -lgcov --coverage -I./include -L../lib -l my

all:    $(NAME)

$(NAME):	$(OBJ)
	make -C ../lib/
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

test_run : fclean $(OBJ)
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
	gcc -o $(NAME) $(SRC) -g
	valgrind --leak-check=full --show-leak-kinds=definite --track-origins=yes ./$(NAME) champ/champ_test.s

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_TEST)

re:     fclean all
