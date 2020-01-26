##
## Roméo's PROJECT, 2018
## Makefile
## File description:
## Le Makefile de la NORMINETTE
##

FPEPI = src/epinorm/
FPSRC = src/

SRC =	$(FPSRC)main.c			\
		$(FPSRC)tools.c			\
		$(FPSRC)norminette.c	\
		$(FPSRC)init.c			\
		$(FPSRC)print.c			\
		$(FPEPI)a_error.c		\
		$(FPEPI)c_error.c		\
		$(FPEPI)f_error.c		\
		$(FPEPI)g_error.c		\
		$(FPEPI)l_error.c		\
		$(FPEPI)o_error.c		\
		$(FPEPI)v_error.c		\
		$(FPEPI)h_error.c		\
		$(FPSRC)lookingfor.c	\
		$(FPSRC)free.c			\

OBJ =	$(SRC:.c=.o)

CFLAGS = -Iinclude/ -Llib/my -lmy

NAME =	norminette

WALL = -W -Wall -Wextra

CC	=	gcc -g3

all:	$(NAME)

$(NAME):	$(OBJ)
			make -C ./lib/my
			gcc -o $(NAME) $(OBJ) $(CFLAGS) $(WALL)
			rm -f $(OBJ)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)
		rm -f ../lib/my/libmy.a
		rm -f lib/my/libmy.a

re: fclean all

valgrind:	$(OBJ)
			make -C ./lib/my
			$(CC) -o $(NAME) $(OBJ) $(CFLAGS)
			rm -f $(OBJ)
			valgrind ./norminette
