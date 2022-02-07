#include <memory>
#include <limits>
#include <iostream>
#include "vector.hpp"

#define NORMAL	"\033[0m"
#define ORANGE	"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"

#define TAB '\t'
#define TAB2 "\t\t"

using std::cout;
using std::endl;

#include <vector>

template <typename T> void	print_info(vector<T> v);

int main()
{
	ft::vector<int>		v(10);

	v.push_back(69);
	v.push_back(70);

	print_info(v);

	return (0);
}

#define COLUMNS 10

template <typename T>
void	print_info(ft::vector<T> v)
{
	static short number = 1;

	cout << CYAN << "TEST #" << number++ << " {" << endl;
		cout << GREEN	<< TAB << "size: " << v.size() << endl;
		cout << BLUE	<< TAB << "max_size: " << v.max_size() << endl;
		cout << NORMAL	<< TAB << "capacity: " << v.capacity() << endl;

		unsigned int			i;
		ft::vector<int>::iterator	it;

		cout << TAB << MAGENTA << "elements: {" << endl;
		it = v.begin();
		while (it != v.end())
		{
			i = 0;
			cout << TAB2;
			while (it != v.end() && i++ < COLUMNS)
				cout << *it++ << ' ';
			cout << endl;
		}
		cout << TAB2 << '}' << endl;
	cout << CYAN << TAB << '}' << endl << endl;
}
