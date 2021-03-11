##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

NAME    =   corewar

all:
	make -C lib/
	make -C asm/
	make -C corewar/

clean:
	make -C corewar/ clean
	make -C asm/ clean
	find . -type f \(  -name "*~" -o -name "#*#" \) -delete
	find . -type f \( -name "*.gcno" -o -name "*.gcda" \) -delete

fclean:
	make -C lib/ fclean
	make -C corewar/ fclean
	make -C asm/ fclean

re:     fclean all
