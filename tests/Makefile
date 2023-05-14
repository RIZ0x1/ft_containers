CXX		= clang++

VECTOR	= vector_test
STACK	= stack_test
MAP		= map_test

VECTOR_HDRS	=	../ft_utils/enable_if.hpp ../ft_utils/is_integral.hpp					\
				../iterator/iterators_core.hpp ../iterator/VectorIterator.hpp			\
				..iterator/VectorIterator.tpp ../vector/vector.hpp ../vector/vector.tpp

STACK_HDRS	=	$(VECTOR_HDRS) ../stack.hpp

MAP_HDRS	=	../ft_utils/lexicographical_compare.hpp ../iterator/iterators_core.hpp	\
				../iterator/MapIterator.hpp ../iterator/MapIterator.tpp					\
				../map/map.hpp ../map/map.tpp

VECTOR_SRC	= vector_unit_tests.cpp 
MAP_SRC		= map_unit_tests.cpp
STACK_SRC	= stack_unit_tests.cpp

VECTOR_OBJS	= $(VECTOR_SRC:%.cpp=%.o)

INC	= ../ft_utils/ ../iterator/ ../vector/ ../map/ ../stack/

all: $(VECTOR) $(MAP)

vector: $(VECTOR)

map: $(MAP)

fclean:
	rm -f $(VECTOR) $(MAP) $(STACK)

re: fclean all

$(VECTOR):
	$(CXX) $(VECTOR_SRC) -o $(VECTOR)

$(STACK):
	$(CXX) $(STACK_SRC) -o $(STACK)

$(MAP):
	$(CXX) $(MAP_SRC) -o $(MAP)

%.cpp: %o
	$(CXX) -c $<
