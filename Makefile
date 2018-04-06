##
## EPITECH PROJECT, 2017
## Lem-in
## File description:
## Makefile
##

SRC_DIR=	src

SRC=		$(SRC_DIR)/lem_in.c		\
		$(SRC_DIR)/linked_list.c	\
		$(SRC_DIR)/parsing.c		\
		$(SRC_DIR)/get_names.c		\
		$(SRC_DIR)/detect.c		\
		$(SRC_DIR)/display.c		\

OBJ=		$(SRC:.c=.o)

CFLAGS= 	-Wall -Wextra -g3

CPPFLAGS=	-I include

LDFLAGS=	-L lib/my/ -l my

NAME=		lem_in

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C lib/src/
		gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		make clean -C lib/src/
		rm -f $(OBJ)

fclean: 	clean
		make fclean -C lib/src/
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
