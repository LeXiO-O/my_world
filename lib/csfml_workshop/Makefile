##
## EPITECH PROJECT, 2026
## makefile
## File description:
## makefile
##

SRC 	=		close_window.c		\
				create_window.c		\
				replace_texture.c		\
				helper_text_button.c		\
				helper_text_key.c		\

OBJ		=		$(SRC:.c=.o)

NAME = ../../libcsfml_ws.a

all: 	$(NAME)

$(NAME):		$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: 	fclean all
