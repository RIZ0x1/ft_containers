CXX		= clang++
FLGS	= -g #-Wall -Wextra -Werror -std=c++98

NAME		= ft_out std_out

VECTOR_HDRS	= vector.hpp vector.tpp
ITER_HDRS	= iterator.hpp

TESTS		= main.cpp
FT_TESTS	= $(addprefix tests/ft_, $(TESTS))
STD_TESTS	= $(addprefix tests/std_, $(TESTS))

HDRS		= $(addprefix vector/, $(VECTOR_HDRS)) $(addprefix iterator/, $(ITER_HDRS))
SRCS		= $(addprefix vector/, $(VECTOR_SRCS)) $(addprefix iterator/, $(ITER_SRCS))
OBJS		= $(SRCS:.cpp=.o)
INCLUDES	= -I vector/ -I iterator/

.PHONY: all clean fclean re

all: $(NAME)

clean:
	rm -f $(OBJS)
	rm -f std_main.o
	rm -f ft_main.o

fclean: clean
	rm -f $(NAME)

re: fclean all

$(NAME): $(OBJS)
	$(CXX) $(FLGS) $(INCLUDES) $(OBJS) $(STD_TESTS) -o std_out
	$(CXX) $(FLGS) $(INCLUDES) $(OBJS) $(FT_TESTS) -o ft_out

%.o: %.cpp $(HDRS)
	$(CXX) $(INCLUDES) $(FLGS) -c $< -o $@
