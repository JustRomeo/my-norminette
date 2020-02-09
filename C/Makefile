##
## Roméo's PROJECT, 2018
## Makefile
## File description:
## Le Makefile de la NORMINETTE
##

FULLPWD = /home/romeo/norminette/

FEPI = src/epinorm/
FPSRC = src/

SRC =	$(FPSRC)main_c_files.c	\
		$(FPSRC)tools.c			\
		$(FPSRC)norminette.c	\
		$(FPSRC)init.c			\
		$(FPSRC)print.c			\
		$(FEPI)a_error.c		\
		$(FEPI)c_error.c		\
		$(FEPI)f_error.c		\
		$(FEPI)g_error.c		\
		$(FEPI)l_error.c		\
		$(FEPI)o_error.c		\
		$(FEPI)v_error.c		\
		$(FEPI)h_error.c		\
		$(FPSRC)lookingfor.c	\
		$(FPSRC)free.c			\

OBJ =	$(SRC:.c=.o)

NAME =	norminette_c.a

CC	=	ar rc

all:	$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(NAME) $(OBJ)
			rm -f $(OBJ)
			cp $(NAME) $(FULLPWD)/library/

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
