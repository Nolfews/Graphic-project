##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

INCLUDES	=	-I ./include

SRC	=	src/main.c						\
		src/free.c			 			\
		src/parsing.c					\
		src/window_management.c			\
		src/loop.c						\
		src/layer_manipulation.c		\
		src/get_mouse_pos.c				\
		src/buttons/do_buttons_actions.c\
		src/buttons/new_button.c		\
		src/buttons/open_button.c		\
		src/buttons/save_button.c		\
		src/buttons/pencil_button.c		\
		src/buttons/rubber_button.c		\
		src/buttons/help_button.c		\
		src/buttons/about_button.c		\
		src/buttons/shape_buttons.c		\
		src/buttons/size_buttons.c		\
		src/events/events.c				\
		src/events/events_check_button.c\
		src/events/update_top_bar.c		\
		src/events/events_drawing.c		\
		src/events/update_side_menu.c	\
		src/events/events_color.c		\
    	src/init/init_side_menu.c		\
		src/init/init.c					\
		src/init/init_textures.c		\
		src/init/init_button.c			\
		src/init/init_top_bar.c			\
		src/init/init_button_functions_top.c\
		src/init/init_button_functions_side.c\
		src/init/init_drawing_board.c	\
		src/draw/draw_text.c			\
		src/draw/draw_side_menu.c		\
		src/draw/draw.c					\
		src/draw/draw_top_bar.c			\
		src/draw/draw_button.c			\
		src/draw/draw_board.c			\
		src/draw/draw_line.c			\
		lib/my_strcpy.c					\
		lib/my_strcmp.c					\
		lib/my_strlen.c					\
		lib/linked_list_utils.c			\
		lib/my_putchar.c				\
		lib/my_putstr.c					\
		lib/my_put_nbr.c				\
		lib/mini_printf.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_paint

LIBS	= -lm -lcsfml-system -lcsfml-graphics -lcsfml-window

TESTS_FILES	=

CC	=	gcc

.PHONY	=	all clean fclean re

CFLAGS	+=	-Wall -Wextra -Werror $(INCLUDES) $(LIBS)

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm $(OBJ)

fclean:	clean
	rm $(NAME)

re:	fclean	all

tests:	$(OBJ)
	gcc -o unit_tests $(TESTS_FILES) $(OBJ) $(CFLAGS) -lcriterion --coverage

tests_run:	tests
	./unit_tests --verbose
