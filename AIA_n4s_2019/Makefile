
##
## EPITECH PROJECT, 2019
## tetris
## File description:
## Makefile
##

SRC	=	src/main.c				\
		src/commands/command.c	\
		src/commands/lidar.c	\
		src/init.c				\
		src/launch.c			\
		src/ia/my_ia.c			\


OBJ	=	$(SRC:.c=.o)

NAME	=	ai

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
#	$(MAKE) -C tests/ --no-print-directory
#	./unit-tests

clean:
	rm -f $(OBJ)
#	$(MAKE) -C ./tests clean --no-print-directory

fclean:	clean
	rm -f lib/my/libmy.a lib/libmy.a
	rm -f $(NAME)
#	$(MAKE) -C ./tests fclean --no-print-directory

re:	fclean all
