##
## EPITECH PROJECT, 2024
## Arcade
## File description:
## Core Makefile
##

SRC			=							\
				src/class/door.cpp		\
				src/class/game.cpp		\
				src/class/object.cpp	\
				src/class/player.cpp	\
				src/class/room.cpp		\
				src/class/lever.cpp		\
				src/main.cpp			\

CXX_OBJS			= $(SRC:.cpp=.o)

NAME		= TOAST


INCLUDE 	= -I./includes/ -I./src/class/
GRAPHFLAG	= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
CXXFLAGS 	= -std=c++20 -Wall -Wextra -Werror -g $(INCLUDE) $(GRAPHFLAG)

all: $(NAME)

$(NAME): $(CXX_OBJS)
	g++ -o $(NAME) $(CXX_OBJS) $(CXXFLAGS)

clean:
	rm -f $(CXX_OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all
