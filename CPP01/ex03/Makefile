NAME = human

SRCS	=	./main.cpp\
./HumanA.cpp\
./HumanB.cpp\
./Weapon.cpp\

OBJS	=	${SRCS:%.cpp=${OBJ_D}%.o}

SRC_D =	src/

OBJ_D = objs/

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

HEADER = ./headers/HumanA.hpp\
./headers/HumanB.hpp\
./headers/Weapon.hpp\

all		:
	@make --no-print-directory ${NAME}

${OBJS}	:	${OBJ_D}%.o: ${SRC_D}%.cpp ${HEADER}
	${CC}	${CFLAGS} -c $< -o $@

${NAME}	:	${OBJ_D} ${OBJS} Makefile ${HEADER}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

${OBJ_D}:
	@mkdir -p ${OBJ_D}

clean	:
	rm -rf ${OBJ_D}

fclean	:	clean
	rm -f ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re