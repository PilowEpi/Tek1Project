##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC		=	src/main.c 										\
			src/launch/loader.c 							\
			src/initialize/initialize_window.c 				\
			src/initialize/initialize_scene.c 				\
			src/initialize/generic/generic_init_sprite.c 	\
			src/initialize/generic/create_sprite.c 			\
			src/initialize/generic/create_button.c 			\
			src/initialize/generic/create_text.c 			\
			src/initialize/initialize_defender.c 			\
			src/launch/play_game.c 							\
			src/launch/draw_game.c 							\
			src/scene/start_menu.c 							\
			src/scene/start_option.c 						\
			src/scene/start_levels.c 						\
			src/scene/start_end.c							\
			src/scene/start_pause.c							\
			src/game_engine/handle_shoot.c					\
			src/event/event_menu.c 							\
			src/event/event_defender.c 						\
			src/event/event_option.c 						\
			src/event/event_levels.c 						\
			src/event/event_pause.c							\
			src/event/event_end.c							\
			src/button/swap_scene.c 						\
			src/button/close.c 								\
			src/button/swap_world.c 						\
			src/button/size_game.c 							\
			src/launch/destroy.c 							\
			src/initialize/initialize_enemy.c 				\
			src/initialize/initialize_spritesheet.c			\
			src/game_engine/draw_defender.c					\
			src/game_engine/tower.c							\
			src/game_engine/tower_function.c				\
			src/game_engine/tower_management.c				\
			src/game_engine/portal.c						\
			src/game_engine/enemy.c							\
			src/game_engine/animation.c						\
			src/game_engine/draw_defender_scene.c			\
			src/game_engine/draw_defender_minimap.c			\
			src/game_engine/draw_defender_main.c			\
			src/game_engine/defender_handling.c				\
			src/game_engine/enemy_utils.c					\

OBJ     =       $(SRC:.c=.o)

NAME	=	my_defender

CFLAGS	=	-Wall -Wextra -I./include -I../include -Llib -l my

CSFML_FLAGS	= -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

all:    $(NAME)

$(NAME):	$(OBJ)
	make -C lib/
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(CSFML_FLAGS)

clean:
	rm -f $(OBJ)
	find . -type f \(  -name "*~" -o -name "#*#" \) -delete
	find . -type f \( -name "*.gcno" -o -name "*.gcda" \) -delete

valgrind: fclean
	clear
	make -C lib/
	gcc -o $(NAME) $(SRC) $(CFLAGS) $(CSFML_FLAGS) -g
	valgrind --leak-check=full --show-leak-kinds=definite --track-origins=yes ./$(NAME)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_TEST)
	make -C lib/ fclean

re:     fclean all
