NAME = zombie.a

CC = cc

FLAGS = -Wall -Werror -Wextra

INCS= Zombie.hpp

SRC = ./newZombie.cpp randomChump.cpp Zombie.cpp main.cpp\

OBJ = $(SRC:.c=.o)

%.o:%.c $(INCS)
	$(CC) $(FLAGS) -c $< -o $@

all : $(NAME)
$(NAME):		$(OBJ)
				ar rcs $(NAME) $(OBJ)
clean:
		rm -f $(OBJ)
fclean: clean
		rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re bonus