NAME = zombie

CC = c++ -std=c++98

FLAGS = -Wall -Werror -Wextra -g

SRC = ./main.cpp\

OBJ = $(SRC:.c=.o)

%.o:%.c
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
