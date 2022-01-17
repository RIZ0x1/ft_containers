CXX		= g++
FLGS	= -Wall -Wextra -Werror -std=c++98

NAME	= out
HDRS	= vector.hpp #map.hpp stack.hpp
SRCS	= std_main.cpp
OBJS	= $(SRCS:.cpp=.o)

.PHONY: all clean fclean re

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(NAME): $(OBJS)
	$(CXX) $(FLGS) $(OBJS) -o out

%.o: %.cpp $(HDRS)
	$(CXX) $(FLGS) -c $< -o $@

