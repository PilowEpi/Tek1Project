##
## EPITECH PROJECT, 2019
## project
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/event.c	\
		src/loop.c	\
		src/init.c	\
		src/file.c 	\
		src/light/intersect.c	\
		src/light/init.c		\
		src/light/raycast.c		\
		src/light/update.c		\
		src/light/utils.c		\
		src/light/clean_ray.c	\
		src/map/map_read.c		\
		src/map/light.c			\
		src/map/room.c			\
		src/map/wall.c			\
		src/map/information.c	\
		src/map/init_entity.c	\
		src/map/entity.c		\
		src/enemies/item.c		\
		src/enemies/enemy.c			\
		src/enemies/enemy_loot.c	\
		src/enemies/enemy_body.c	\
		src/enemies/item_body.c		\
		src/enemies/static_read.c	\
		src/player/movement.c		\
		src/player/rotation.c		\
		src/player/end_room.c		\
		src/player/attack.c			\
		src/player/items.c			\
		src/entity/draw.c			\
		src/entity/math_utils.c		\
		src/entity/movement.c		\
		src/entity/copy.c			\
		src/rooms/getter.c			\
		src/rooms/debugger.c		\
		src/bank/getter.c			\
		src/bank/debugger.c			\
		src/hud/init.c				\
		src/hud/utils.c				\
		src/particle/engine.c		\
		src/particle/anim.c			\
		src/particle/system.c		\
		src/particle/part.c			\
		src/particle/desc/desc.c	\
		src/particle/desc/move.c	\
		src/init/init_game.c						\
		src/init/effects.c							\
		src/hud/init2.c								\
		src/init/init_basic.c						\
		src/game/play_game.c						\
		src/game/event/main_event.c					\
		src/game/draw/draw_scene.c					\
		src/game/draw/draw_menu.c					\
		src/game/draw/draw_option.c					\
		src/game/draw/draw_pause.c					\
		src/game/draw/draw_tuto.c					\
		src/init_player.c							\
		src/game/draw/draw_end.c					\
		src/game/draw/draw_skill.c					\
		src/game/event/menu_event.c					\
		src/game/event/option_event.c				\
		src/game/event/pause_event.c				\
		src/game/event/end_event.c					\
		src/game/event/skill_event.c				\
		src/game/event/button_all_event.c			\
		src/game/event/tuto_event.c					\
		src/destroy/main_destroy.c					\
		src/game/button/close.c						\
		src/game/button/swap_scene.c				\
		src/game/button/sound.c						\
		src/game/button/game_end.c					\
		src/loop2.c									\
		src/loop3.c									\
		src/player/attack2.c						\
		src/player/attack3.c						\
		src/game/button/more.c						\
		src/game/button/utils.c						\
		src/bullet/bullet.c							\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

CFLAGS	=	-Iinclude -Llib -lmy -l_csfml -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

all:
	$(MAKE) -C lib/my --no-print-directory
	$(MAKE) -C lib/my clean --no-print-directory
	$(MAKE) -C lib/lib_csfml --no-print-directory
	$(MAKE) $(NAME) --no-print-directory

$(NAME):$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

debug:
	$(MAKE) -C lib/my --no-print-directory
	$(MAKE) -C lib/my clean --no-print-directory
	$(MAKE) -C lib/lib_csfml --no-print-directory
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

re:	fclean all
