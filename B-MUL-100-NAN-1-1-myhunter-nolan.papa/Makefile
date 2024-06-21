##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

SRC 	=	main.c									\
			window/open_window.c					\
			sprites/sprite_move.c					\
			sprites/background.c					\
			sprites/set_sprite.c					\
			sprites/draw_sprite.c					\
			sprites/sprite_anime.c					\
			lib/my_put_nbr.c						\
			lib/my_putchar.c						\
			lib/my_putstr.c							\
			lib/my_strlen.c							\
			events/analyse_events.c					\
			music/load_music.c						\

BINNAME = 	my_hunter

OBJ		= 	$(SRC:.c=.o)

lib 	=	-l csfml-graphics -l csfml-window -l csfml-audio -l csfml-system

all: 		$(BINNAME)

$(BINNAME):	$(OBJ)
			gcc -o $(BINNAME) $(OBJ) $(lib)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(BINNAME)

re:			fclean all
