##
## EPITECH PROJECT, 2019
## Makefile for libmy build
## File description:
## Build the my library
##

SRC 	=	conf.c					\
			is_num.c				\
			memory.c				\
			my_getnbr.c				\
			my_int_to_str.c			\
			my_printf.c				\
			my_put_nbr.c			\
			my_put_unsigned_nbr.c	\
			my_putnbr_base.c		\
			my_putstr.c				\
			my_str_is.c				\
			nstrings.c				\
			parser1.c				\
			parser2.c				\
			pf_put_nbr.c			\
			printers1.c				\
			printers2.c				\
			printers3.c				\
			printers4.c				\
			put_double.c			\
			strings.c				\
			utils.c					\
			my_malloc.c				\

SRC2 =		lld/lld_db.c 			\
			lld/lld_free.c			\
			lld/lld_free_r.c		\
			lld/lld_init.c			\
			lld/lld_insert.c		\
			lld/lld_insert_node.c	\
			lld/lld_len.c			\
			lld/lld_len_db.c		\
			lld/lld_lld_to_tab.c	\
			lld/lld_pop.c			\
			lld/lld_pop_node.c		\
			lld/lld_print_int.c		\
			lld/lld_print_str.c		\
			lld/lld_read.c			\
			lld/lld_sort.c			\
			lld/lld_tab_to_lld.c	\
			lld/lld_write.c			\
			ucp/is_.c				\
			ucp/is_made.c			\
			ucp/ucp.c				\
			ucp/ucp_tab.c			\
			lld/lld_init_my.c		\
			lld/lld_insert_my.c		\
			lld/lld_pop_my.c		\

OBJ1=	$(SRC:.c=.o)
OBJ2=	$(SRC2:.c=.o)

NAME	=	libmy.a

HEADER	=	my.h

all:	build

build:	$(NAME)

$(NAME):$(OBJ1) $(OBJ2)
	ar rc $(NAME) $(OBJ1) $(OBJ2)
	cp $(NAME) ../
	cp $(HEADER) ../../include/
	cp sh.h ../../include/

clean:
	rm -f $(OBJ1)
	rm -f $(OBJ2)

fclean: clean
	rm -f $(NAME)
	rm -f ../../include/sh.h
	rm -f ../../include/$(HEADER)
