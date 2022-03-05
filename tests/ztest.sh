#FUNCTION
NORMAL="\033[0m"
ORANGE="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
BLUE="\033[34m"
MAGENTA="\033[35m"
CYAN="\033[36m"
function find_diff()
{
	diff="0"
	./ft_output > txt/ft.txt
	./std_output > txt/std.txt
	diff txt/ft.txt txt/std.txt > txt/$1_diff.txt
	diff='cat $( txt/$1_diff.txt )'
	sed -i '' 's/>/std:/' txt/$1_diff.txt
	sed -i '' 's/</ft:/' txt/$1_diff.txt
	rm ft_output
	rm std_output
	if [ "$diff" == "0" ]
	then
		echo "$1 [✅]"
	else
		echo "$1 [❌]"
		echo " $GREEN your mistakes recorder in ./txt/vector_diff.txt"
	fi
}
#VECTOR
echo "$MAGENTA COMPILING VECTOR TESTS 🧐 "
c++ -Wall -Werror -Wextra -std=c++98 -I ../ft_utils -I ../iterator -I ../vector vector.cpp -o ft_output
c++ -Wall -Werror -Wextra -std=c++98 -D NS=std vector.cpp -o std_output
echo "$GREEN COMPLETE 😎 $MAGENTA"
find_diff vector

#MAP
# c++ -Wall -Werror -Wextra -std=c++98 -I ../ft_utils -I ../iterator -I ../map map.cpp -o ft_output
# c++ -Wall -Werror -Wextra -std=c++98 map.cpp -D NS=std -o std_output
# find_diff map

#STACK
# c++ -Wall -Werror -Wextra -std=c++98 -I ../ft_utils -I ../iterator -I ../map stack.cpp -o ft_output
# c++ -Wall -Werror -Wextra -std=c++98 stack.cpp -D NS=std -o std_output
# find_diff stack