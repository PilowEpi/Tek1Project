##
## EPITECH PROJECT, 2020
## MUL_my_rpg_2019
## File description:
## Makefile
##

SRC 	=	*.c

OBJ	=	$(SRC:.c=.o)

NAME	=	lib_csfml.a

HEADER	=	lib_csfml.h

STRUCT_HEADER	=	struct_csfml.h

build:
	gcc -c $(SRC) -g
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
	cp $(HEADER) ../../include/
	cp $(STRUCT_HEADER) ../../include/

clean:
	find . -name "*.o" -delete

fclean: clean
	rm $(NAME)