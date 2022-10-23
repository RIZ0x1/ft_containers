VECTOR	= vector_test
MAP	= map_test
STACK	= stack_test

VECTOR_SRCS	= vector_unit_tests.cpp
MAP_SRC		= map_unit_tests.cpp
STACK_SRC	= stack_unit_tests.cpp

INC	= ../ft_utils/ ../iterator/ ../vector/ ../map/ ../stack/

all: $(VECTOR) $(MAP)

fclean:
	rm -f $(VECTOR) $(MAP) $(STACK)

re: fclean all

$(VECTOR):
	$(CC) $(VECTOR_SRC) -o $(VECTOR)

$(MAP):
	$(CC)
