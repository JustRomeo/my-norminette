##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Le Makefile de la lib
##

SRCS = src/
BODY = $(SRCS)Body/
PRIN = $(SRCS)Displayer/
FLAG = $(SRCS)Flags/


SRC =	$(SRCS)main.cpp				\
		$(BODY)normimain.cpp		\
		$(FLAG)infos.cpp			\
		\
		src/Handler/Errors.cpp		\
		src/Handler/Displayer.cpp	\
		src/Env/Exception.cpp		\
		src/Env/System.cpp			\
		\
		src/Normes/C.cpp			\
		src/Normes/H.cpp			\
		src/Normes/ASM.cpp			\
		src/Normes/Cpp.cpp			\
		src/Normes/Hpp.cpp			\
		src/Normes/Haskell.cpp		\
		src/Normes/Python.cpp		\

SRCT =	tests/test.cpp	\

OBJ =	$(SRC:.cpp=.o)
OBJT =	$(SRC:.c=.o)

CC =	g++

CRIT =	--coverage -lcriterion

WALL =	-Wall -Wextra -Werror

NAME =	norminette
CRITERION = unit_tests

CPPFLAGS =	-I./include/	\
			-I./Class		\

all:	$(NAME)

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS) $(WALL)
			rm -f $(OBJ)

nuke:
	find . \( -name '*~' \) -print -delete
	find . \( -name '*.o' \) -print -delete
	find . \( -name '*.a' \) -print -delete
	find . \( -name '*.gcno' \) -print -delete
	find . \( -name '*.gcda' \) -print -delete

tests_run:	$(OBJ)
			$(CC) -o $(CRITERION) $(CRIT) $(OBJ) $(INCLUDE)
			./$(CRITERION)

valgrind:	$(OBJ)
			$(CC) -g3 -o $(NAME) $(OBJ) $(CPPFLAGS) $(WALL)
			valgrind ./$(NAME)

exe:	all
		./$(NAME)
		rm -vf *.o
		rm -f $(NAME)

clean_test: $(OBJ)
			$(CC) -o $(CRITERION) $(CRIT) $(OBJ)
			./$(CRITERION)
			gcovr
			rm -vf *.o
			rm -vf *.gcno
			rm -vf *.gcda
			rm $(CRITERION)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ)
	rm -f $(NAME)

re:	fclean all
