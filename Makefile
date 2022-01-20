CXX		= clang++
FLGS	= -g #-Wall -Wextra -Werror -std=c++98

VECTOR_HDRS	= vector.hpp vector.tpp

ITER_HDRS	= iterator.hpp

HDRS		= $(addprefix iterator/, $(ITER_HDRS)) $(addprefix vector/, $(VECTOR_HDRS)) 
SRCS		= $(addprefix iterator/, $(ITER_SRCS)) $(addprefix vector/, $(VECTOR_SRCS)) 
OBJS		= $(SRCS:.cpp=.o)
INCLUDES	= -I vector/ -I iterator/

.PHONY: all clean fclean re ft std

all: ft std

clean:
	rm -f $(OBJS) tests/ft_main.o tests/std_main.o

fclean: clean
	rm -f std_out ft_out

re: fclean all

ft: $(OBJS) tests/ft_main.o
	$(CXX) $(FLGS) $(INCLUDES) $(OBJS) tests/ft_main.o -o ft_out

std: $(OBJS) tests/std_main.o
	$(CXX) $(FLGS) $(INCLUDES) $(OBJS) tests/std_main.o -o std_out

%.o: %.cpp
	$(CXX) $(INCLUDES) $(FLGS) -c $< -o $@
