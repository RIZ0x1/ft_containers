#include <vector>
#include <memory>
#include <limits>
#include <iostream>


#define NORMAL	"\033[0m"
#define ORANGE	"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"

#define TAB '\t'
#define TAB2 "\t\t"

#ifndef NS
# define NS ft
# include "vector.hpp"
#endif

using std::cout;
using std::endl;
using NS::vector;


template <typename T>
void	print_info(vector<T>& v, const std::string& message = "TEST");

int main()
{
	vector<int>			v0;
	print_info(v0);

	std::allocator<char>	alloc0;
	vector<char>		v1(alloc0);
	print_info(v1);

	std::allocator<char>	alloc1;
	vector<char>		v2(8, '8', alloc1);
	print_info(v2);

	v0.assign(70, 77);                                           // // ASSIGN
	print_info(v0);                                              //
	v1.assign<vector<char>::iterator>(v2.begin(), v2.end()); //
	print_info(v1);

	char c = '0';                                                                // // ITERATOR
	for (vector<char>::iterator it = v1.begin(); it != v1.end(); it++, c++)  //
		*it = c;                                                                 //

	try {                                      // // AT
		for (int i = 0; i < 10; i++)           //
			cout << "[" << v1.at(i) << "] ";   //
	}                                          //
	catch (std::logic_error &e) {              //
		cout << e.what() << "] ";              //
	}                                          //
	cout << endl;                              //

	vector<char>::pointer 	p = v1.data(); // // DATA
	for (; p != &(*v1.end()); p++)             //
		cout << '[' << *p << "] ";             //
	cout << endl;                              //

	v1.reserve(50);
	print_info(v1);

	vector<char>::iterator	it = v1.begin();  // // ERASE
	for (size_t i = 0; i < 4; i++)                //
		(it++);                                   //
	v1.erase(it);                                 //
	print_info(v1);                               //
	it = v1.begin();                              //
	for (size_t i = 0; i < 4; i++)                //
		(it++);                                   //
	v1.erase(v1.begin(), it);                     //
	print_info(v1);                               //

	v1.pop_back();      // 5 6 [7]   // POP_BACK
	print_info(v1);     //
	v1.pop_back();      // 5 [6]
	v1.pop_back();      // [5]
	print_info(v1);     //
	// v1.pop_back();      // empty
	// print_info(v1, "BUGGED");     //

	v0.assign(40, 69);            // // RESIZE
	print_info(v0);               //
	v0.resize(69, 70);            //
	print_info(v0, "RESIZE");     //
	try { v0.resize(-1); }        //
	catch (std::exception &e) { } //

	vector<int>		new_v0;    // // SWAP
	v0.swap(new_v0);               //
	print_info(v0, "V0");          //
	print_info(new_v0, "NEW_V0");  //

	vector<int>::iterator	iit = new_v0.begin();  // // INSERT
	for (size_t i = 0; i < 10; i++)                    //
		(iit++);                                       //
	int x = 50;                                        //
	new_v0.insert(iit, x);                             //
	print_info(new_v0, "INSERT");                      //

	iit = new_v0.begin();                       // // iterator::operator []
	for (size_t i = 0; i < new_v0.size(); i++)  //
		cout << iit[i] << TAB;                  //
	cout << endl;                               //

	return (0);
}

template <typename T>
void	print_info(vector<T>& v, const std::string& message)
{
	cout << endl << CYAN << message << "  {" << endl;
		cout << GREEN	<< TAB << "size: " << v.size() << endl;
		cout << BLUE	<< TAB << "max_size: " << v.max_size() << endl;
		cout << NORMAL	<< TAB << "capacity: " << v.capacity() << endl;

		unsigned int						i;
		typename vector<T>::iterator	it;

		cout << TAB << MAGENTA << "elements: {" << endl;
		it = v.begin();
		const unsigned int	COLUMNS = 10;
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
