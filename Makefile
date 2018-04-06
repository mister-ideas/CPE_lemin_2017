##
## EPITECH PROJECT, 2017
## Lem-in
## File description:
## Makefile
##

SRC_DIR=	src/

LIB_SRC_DIR=	lib/src/

SRC=		$(SRC_DIR)lem_in.c		\
		$(SRC_DIR)linked_list.c		\
		$(SRC_DIR)parsing.c		\
		$(SRC_DIR)get_names.c		\
		$(SRC_DIR)detect.c		\
		$(SRC_DIR)display.c		\
		$(SRC_DIR)errors.c		\

OBJ=		$(SRC:.c=.o)

CFLAGS= 	-Wall -Wextra

CPPFLAGS=	-I include

LDFLAGS=	-L lib/my/ -l my

NAME=		lem_in

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C $(LIB_SRC_DIR)
		gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		make clean -C $(LIB_SRC_DIR)
		rm -f $(OBJ)

fclean: 	clean
		make fclean -C $(LIB_SRC_DIR)
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
