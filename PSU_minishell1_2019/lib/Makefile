##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

SRC	=	my/my_putchar.c	\
		my/my_put_nbr.c	\
		my/my_strdup.c	\
		my/my_putstr.c	\
		my/my_strlen.c	\
		my/my_strcat_m.c	\
		my/is_op.c	\
		my/is_num.c	\
		my/my_atoi.c	\
		my/sum_stdarg.c	\
		my/disp_stdarg.c	\
		my/my_printf.c	\
		my/my_strcmp.c	\
		my/my_print_str.c \
		my/my_print_nbr.c \
		my/my_print_error.c \
		my/my_print_char.c  \
		my/my_size_of_int.c    \
		my/my_put_octal.c    \
		my/my_put_unsi_int.c    \
		my/my_print_unsi_int.c \
		my/my_stoi.c \
		my/my_print_ptr.c \
		my/my_put_bin.c \
		my/my_print_bin.c \
		my/my_put_hexa_min.c \
		my/my_print_hexa_min.c \
		my/my_put_hexa_maj.c \
		my/my_print_hexa_maj.c \
		my/my_print_percent.c \
		my/my_str_to_word_array.c \
		my/free_my_array.c \
		my/my_getnbr.c \
		my/my_put_error.c \
		my/my_realloc_cat.c

SRC_TEST	=	../tests/lib_tests/test_sum_stdarg.c	\
				../tests/lib_tests/test_my_printf.c 	\
				../tests/lib_tests/test_my_printf_s.c \
				../tests/lib_tests/test_my_printf_i_d.c	\
				../tests/lib_tests/test_my_printf_o.c \
				../tests/lib_tests/redirect_all_std.c \
				../tests/lib_tests/test_my_printf_x.c \
				../tests/lib_tests/test_my_printf_b.c \
				../tests/lib_tests/test_my_printf_u.c \
				../tests/lib_tests/test_my_printf_c.c \
				../tests/lib_tests/test_my_printf_p.c \
				../tests/lib_tests/test_my_printf_sm.c \
				../tests/lib_tests/test_is_num.c \
				../tests/lib_tests/test_is_op.c \
				../tests/lib_tests/test_my_atoi.c \
				../tests/lib_tests/test_disp_stdarg.c \
				../tests/lib_tests/test_my_size_of_int.c \
				../tests/lib_tests/test_my_stoi.c \
				../tests/lib_tests/test_my_str_to_word_array.c \
				../tests/lib_tests/test_my_strcmp.c \
				../tests/lib_tests/test_my_strdup.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

NAME_TEST	=	unit_test

CMP	=	gcc

CFLAGS	= -Wall -Wextra -g

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

tests_run:
	$(CMP) -o $(NAME_TEST) $(SRC_TEST) $(SRC) -lcriterion --coverage -I ../include
	find . -type f -name "test*.gcno" -delete
	find . -type f -name "test*.gcda" -delete
	./$(NAME_TEST)

clean:
	rm -f $(OBJ)
	find . -type f \(  -name "*~" -o -name "#*#" \) -delete
	find . -type f \( -name "*.gcno" -o -name "*.gcda" \) -delete
	find . -type f -name "unit_test" -delete

fclean:	clean
	rm -f $(NAME)

re:	fclean all
