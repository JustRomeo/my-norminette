##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Le Makefile de la lib
##

SRCS = src/
BODY = $(SRCS)Body/
FLAG = $(SRCS)Flags/
PRIN = $(SRCS)printer/

SRC =	$(SRCS)main.cpp			\
		$(BODY)normimain.cpp	\
		$(FLAG)infos.cpp		\
		$(PRIN)file.cpp			\
		$(PRIN)error.cpp		\
		\
		src/Env/Exception.cpp	\
		src/Errors.cpp			\
		src/Env/System.cpp		\
		\
		src/Normes/Cpp.cpp	\
		src/Normes/Hpp.cpp	\


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
			\
			-L./library -lnorminette_c			\
			-L./library -lnorminette_h			\
			-L./library -lnorminette_asm		\
			-L./library -lnorminette_haskell	\

all:	$(NAME)

$(NAME):	$(OBJ)
			make -C C/
			make -C H/
			make -C ASM/
			make -C Haskell/
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