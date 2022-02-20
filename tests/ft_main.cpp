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

template <typename T> void	print_info(ft::vector<T>& v, const std::string& message = "TEST");

int main()
{
	ft::vector<int>			v0;
	print_info(v0);

	std::allocator<char>	alloc0;
	ft::vector<char>		v1(alloc0);
	print_info(v1);

	std::allocator<char>	alloc1;
	ft::vector<char>		v2(8, '8', alloc1);
	print_info(v2);

	v0.assign(70, 77);
	print_info(v0);

	v1.assign<ft::vector<char>::iterator>(v2.begin(), v2.end());
	print_info(v1);

	char c = '0';
	for (ft::vector<char>::iterator it = v1.begin(); it != v1.end(); it++, c++)
		*it = c;

	try {
		for (int i = 0; i < 10; i++)
			cout << "[" << v1.at(i) << "] ";
	}
	catch (std::logic_error &e) {
		cout << e.what() << "] ";
	}
	cout << endl;

	ft::vector<char>::pointer 	p = v1.data();
	for (; p != &(*v1.end()); p++)
		cout << '[' << *p << "] ";
	cout << endl;

	v1.reserve(50);
	print_info(v1);

	ft::vector<char>::iterator	it = v1.begin();
	for (size_t i = 0; i < 4; i++)
		(it++);
	v1.erase(it);
	print_info(v1);
	it = v1.begin();
	for (size_t i = 0; i < 4; i++)
		(it++);
	v1.erase(v1.begin(), it);
	print_info(v1);

	v1.pop_back();			// 5 6 [7]
	print_info(v1);		//
	v1.pop_back();			// 5 [6]
	v1.pop_back();			// [5]
	print_info(v1);		//
	v1.pop_back();			// empty
	print_info(v1);		//

	v0.assign(40, 69);
	print_info(v0);
	v0.resize(69, 70);
	print_info(v0);
	v0.resize(-1);

	ft::vector<int>		new_v0;
	v0.swap(new_v0);
	print_info(v0, "V0");
	print_info(new_v0, "NEW_V0");

	ft::vector<int>::iterator	iit = new_v0.begin();
	for (size_t i = 0; i < 10; i++)
		(iit++);
	int x = 50;
	new_v0.insert(iit, x);
	print_info(new_v0);

	return (0);
}

#define COLUMNS 10

template <typename T>
void	print_info(ft::vector<T>& v, const std::string& message)
{
	cout << endl << CYAN << message << "  {" << endl;
		cout << GREEN	<< TAB << "size: " << v.size() << endl;
		cout << BLUE	<< TAB << "max_size: " << v.max_size() << endl;
		cout << NORMAL	<< TAB << "capacity: " << v.capacity() << endl;

		unsigned int						i;
		typename ft::vector<T>::iterator	it;

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
	cout << CYAN << TAB << '}' << endl;
}
