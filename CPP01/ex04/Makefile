NAME = zombie

CC = c++ -std=c++98

FLAGS = -Wall -Werror -Wextra -g

INCS = ./main.hpp\

SRC = ./main.cpp\

OBJ = $(SRC:.c=.o)

%.o:%.c ${INCS}
	$(CC) $(FLAGS) -c $< -o $@

all : $(NAME)
$(NAME):        $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
