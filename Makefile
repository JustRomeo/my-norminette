##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Le Makefile de la lib
##

SRC =	src/main.cpp	\

SRCT =	tests/test.cpp	\

OBJ =	$(SRC:.cpp=.o)
OBJT =	$(SRC:.c=.o)

CC =	g++
CRIT =	--coverage -lcriterion

WALL =	-Wall -Wextra -Werror

NAME =	norminette
CRITERION = unit_tests

CPPFLAGS =	-I ./include/	\
			\
			-L./library -lnorminette_c

all:	$(NAME)

$(NAME):	$(OBJ)
			make -C C
			$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(WALL)
			rm -f $(OBJ)

tests_run:	$(OBJ)
			$(CC) -o $(CRITERION) $(CRIT) $(OBJ) $(INCLUDE)
			./$(CRITERION)

valgrind:	$(OBJ)
			$(CC) -g3 -o $(NAME) $(OBJ) $(CFLAGS) $(WALL)
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