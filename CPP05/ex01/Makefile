NAME 	= Bureaucrat

CXX	 	= c++

CFLAGS	= -Wall -Wextra -Werror -std=c++98 -g -MD -MP

SRCS	= main.cpp \
		Bureaucrat.cpp \
		Form.cpp \
      
OBJS	= $(SRCS:%.cpp=$(OBJ_D)%.o)

OBJ_D 	= objects/
SRC_D	= src/
HEADERS_D = headers/

$(OBJ_D)%.o: $(SRC_D)%.cpp Makefile
	@mkdir -p $(@D)
	$(CXX) -I headers $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $@

DEPS = $(OBJS:.o=.d)

all: $(NAME)

-include $(DEPS)

clean:
	rm -rf $(OBJ_D)

fclean: clean
	rm -f $(NAME)

re: fclean all