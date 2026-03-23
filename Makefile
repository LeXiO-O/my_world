##
## EPITECH PROJECT, 2026
## makefile
## File description:
## makefile
##

.PHONY: all clean fclean re

CC = epiclang

SRC =	src/my_world.c		\
		src/create_sprite.c		\
		src/events/handle_event.c		\
		src/events/menu_to_ingame.c		\
		src/in_game/create_scene_ingame.c		\
		src/in_game/create_helper_text.c		\
		src/in_game/box_handle_save_load.c		\
		src/menu/create_scene_menu.c		\
		src/menu/draw_scene_menu.c		\
		src/matrix/handle_matrix.c		\
		src/menu/handle_mouse_on.c		\
		src/in_game/handle_mouse_ingame.c		\
		src/menu/box_handle_matrix.c		\
		src/in_game/create_buttons.c		\
		src/menu/parsing_std_user.c		\
		src/in_game/handle_keyboard.c		\
		src/matrix/mouse_on_quads.c		\
		src/matrix/create_perlin_matrix.c		\
		src/save_load/manage_load.c		\
		src/save_load/manage_save.c		\
		src/in_game/update_texture.c		\
		src/in_game/buttons/clear.c		\
		src/in_game/buttons/down.c		\
		src/in_game/buttons/help.c		\
		src/in_game/buttons/home.c		\
		src/in_game/buttons/load.c		\
		src/in_game/buttons/quit.c		\
		src/in_game/buttons/reroll.c		\
		src/in_game/buttons/save.c		\
		src/in_game/buttons/six_seven.c		\
		src/in_game/buttons/up.c		\
		src/matrix/draw_quads.c		\
		src/on_click/on_clear.c		\
		src/on_click/on_down.c		\
		src/on_click/on_load.c		\
		src/on_click/on_menu.c		\
		src/on_click/on_play.c		\
		src/on_click/on_quit.c		\
		src/on_click/on_help.c		\
		src/on_click/on_reroll.c		\
		src/on_click/on_save.c		\
		src/on_click/on_six_seven.c		\
		src/on_click/on_up.c		\
		src/free/free.c		\

OBJ =	$(SRC:.c=.o)

NAME =	my_world

CFLAGS =	-g -Wextra -Wall -pedantic -Wshadow -I./ -Wundef -Wpointer-arith		\
			-Wfloat-equal -Winit-self -Wwrite-strings		\
			-Wcast-align -Wmissing-field-initializers

CLIBS =		-g -L ./ -lcsfml_ws -lmy		\
			-lcsfml-graphics -lcsfml-window -lcsfml-audio		\
			-lcsfml-system -lm



ORANGE	= \033[38;5;208m
RESET	= \033[0m

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my/ all
	make -C lib/csfml_workshop/ all
	$(CC) -o $(NAME) $(OBJ) $(CLIBS) $(CFLAGS)
	@echo "$(ORANGE)|| MY_WORLD - VALENTIN LORIS ||$(RESET)"

clean:
	make -C lib/my/ clean
	make -C lib/csfml_workshop/ clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make -C lib/my/ fclean
	make -C lib/csfml_workshop/ fclean
	@echo "$(ORANGE)|| cleaning done ||$(RESET)"

re: fclean all
