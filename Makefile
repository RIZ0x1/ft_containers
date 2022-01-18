CXX		= clang++
FLGS	= #-Wall -Wextra -Werror -std=c++98

NAME		= out

VECTOR_HDRS	= vector.hpp vector.tpp
VECTOR_SRCS	= vector.cpp

ITER_HDRS	= iterator.hpp
ITER_SRCS	= iterator.cpp

HDRS		= $(addprefix vector/, $(VECTOR_HDRS)) $(addprefix iterator/, $(ITER_HDRS))
SRCS		= $(addprefix vector/, $(VECTOR_SRCS)) $(addprefix iterator/, $(ITER_SRCS)) ft_main.cpp
OBJS		= $(SRCS:.cpp=.o)
INCLUDES	= -I vector/ -I iterator/

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
	$(CXX) $(INCLUDES) $(FLGS) -c $< -o $@
