NAME = clap

SRCS	=	./main.cpp ClapTrap.cpp\

OBJS	=	${SRCS:%.cpp=${OBJ_D}%.o}

DEPENDS = ${SRCS:%.cpp=${DP_D}%.d}

SRC_D =	src/

OBJ_D = objs/

DP_D = dpd/

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD

all		:
	@make --no-print-directory ${NAME}

${OBJS}	:	${OBJ_D}%.o: ${SRC_D}%.cpp
	${CC}	${CFLAGS} -c $< -o $@

${NAME}	:	${OBJ_D} ${OBJS} Makefile 
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

${OBJ_D}:
	@mkdir -p ${OBJ_D}

${DP_D}:
	@mkdir -p ${DP_D}

clean	:
	rm -rf ${OBJ_D} ${DP_D}

fclean	:	clean
	rm -f ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re

-include ${DEPENDS}
