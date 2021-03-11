##
## EPITECH PROJECT, 2019
## Makefile for libmy build
## File description:
## Build the my library
##

SRC 	=	*.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

HEADER	=	my.h

build:
	gcc -c $(SRC)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
	cp $(HEADER) ../../include/

clean:
	find . -name "*.o" -delete

fclean: clean
	rm $(NAME)
