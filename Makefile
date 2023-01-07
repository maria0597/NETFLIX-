NAME = netflix

G++ = g++

SRC = main.cpp account.cpp database.cpp film.cpp profilo.cpp serie.cpp
HDR = account.h database.h film.h profilo.h serie.h netflix.h
OBJ = $(SRC:.cpp=.o)

%.o: %.c
	$(G++) -I $(HDR) -c $< -o $@

$(NAME): $(OBJ)
	$(G++) $(OBJ) -o $(NAME)

all: $(NAME)
	make clean

clean: $(NAME)
	rm -f $(OBJ)

fclean:
	rm -f $(NAME) $(OBJ) accounts.txt

re: 
	rm -f $(NAME) $(OBJ)
	make  $(NAME)

.PHONY: all clean fclean re
