NAME = megaphone

SRCS	=	./contact.cpp\

OBJS	=	${SRCS:%.cpp=${OBJ_D}%.o}

SRC_D =	src/

OBJ_D = objs/

CC = c++ -std=c++98

CFLAGS = -Wall -Wextra -Werror

HEADER = contact.hpp

all		:
	@make --no-print-directory ${NAME}

${OBJS}	:	${OBJ_D}%.o: ${SRC_D}%.cpp headers/contact.hpp
	${CC}	${CFLAGS} -c $< -o $@

${NAME}	:	${OBJ_D} ${OBJS} Makefile headers/contact.hpp
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

${OBJ_D}:
	@mkdir -p ${OBJ_D}

clean	:
	rm -rf ${OBJ_D}

fclean	:	clean
	rm -f ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re