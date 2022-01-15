CXX	= clang++
FLGS	= -Wall -Wextra -Werror -std=c++98

NAME	= out
HDRS	= vector.hpp map.hpp stack.hpp
SRCS	= main.cpp
OBJS	= $(SRCS:%.cpp=%.o)

.PHONY: all clean fclean re

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(NAME): $(HDRS) $(OBJS)

%.o: %.cpp
	$(CXX) $(FLGS) -c $< -o $@

