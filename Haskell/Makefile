##
## Roméo's PROJECT, 2018
## Makefile
## File description:
## Le Makefile de la NORMINETTE
##

FULLPWD = /home/romeo/norminette/

SRCS = src/

SRC =	$(SRCS)main_haskell_files.cpp	\
		$(SRCS)file_handler.cpp		\

OBJ =	$(SRC:.cpp=.o)

NAME =	libnorminette_haskell.a

CC	=	ar rc

all:	$(NAME)

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(OBJ)
			rm -f $(OBJ)
			mv $(NAME) $(FULLPWD)library/

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)
		rm -f ../lib/my/libmy.a
		rm -f lib/my/libmy.a

re: fclean all
