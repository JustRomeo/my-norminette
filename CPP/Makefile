##
## Roméo's PROJECT, 2018
## Makefile
## File description:
## Le Makefile de la NORMINETTE
##

FULLPWD = /home/romeo/norminette/

SRCS = src/

SRC =	$(SRCS)main_cpp_files.c	\

OBJ =	$(SRC:.c=.o)

NAME =	norminette_cpp.a

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
