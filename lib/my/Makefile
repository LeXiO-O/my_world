##
## EPITECH PROJECT, 2026
## makefile
## File description:
## makefile lib_ls
##

SRC 	=		cat_in_fonction.c		\
				my_err_msg.c		\
				my_putchar.c		\
				my_int_to_str.c		\
				my_put_nbr.c		\
				my_putstr.c		\
				my_strlen.c		\
				my_getnbr.c		\
				my_str_to_word_array.c		\
				my_str_isnum.c		\
				my_strcat.c		\
				my_strcmp.c		\
				my_strdup.c		\
				my_miniprintf.c		\
				free_array.c		\
				my_strndup.c	\
				my_memcpy.c 	\
				my_memcmp.c 	\
				cpt_tab.c	\

OBJ		=		$(SRC:.c=.o)

NAME = ../../libmy.a

all: 	$(NAME)

$(NAME):		$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: 	fclean all