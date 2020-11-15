##
## Roméo's PROJECT, 2018
## Makefile
## File description:
## Le Makefile de la NORMINETTE
##

FULLPWD = /home/romeo/norminette/

SRCS = src/

SRC =	$(SRCS)main_cpp_files.cpp	\
		$(SRCS)file_handler.cpp		\
		\
		$(SRCS)Errors.cpp	\
		$(SRCS)System.cpp	\
		\
		$(SRCS)Cpp.cpp	\
		$(SRCS)Hpp.cpp	\

OBJ =	$(SRC:.cpp=.o)

# NAME =	libnorminette_cpp.a
NAME = TestCppClass

# CC	=	ar rc
CC = g++

all:	$(NAME)

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) -I./include
			rm -f $(OBJ)
			mv $(NAME) $(FULLPWD)library/

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)
		rm -f ../lib/my/libmy.a
		rm -f lib/my/libmy.a

re: fclean all
