NAME = zombie

SRCS	=	./main.cpp\

OBJS	=	${SRCS:%.cpp=${OBJ_D}%.o}

SRC_D =	src/

OBJ_D = objs/

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

all		:
	@make --no-print-directory ${NAME}

${OBJS}	:	${OBJ_D}%.o: ${SRC_D}%.cpp
	${CC}	${CFLAGS} -c $< -o $@

${NAME}	:	${OBJ_D} ${OBJS} Makefile
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

${OBJ_D}:
	@mkdir -p ${OBJ_D}

clean	:
	rm -rf ${OBJ_D}

fclean	:	clean
	rm -f ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re