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

using std::cout;
using std::endl;
using std::vector;

template <typename T> void	test(vector<T> v);

int main()
{
	cout << YELLOW;
	cout << "############### STD_VECTOR ###############\n" << std::endl;
	cout << NORMAL;
	{
		// ? CONSTRUCTORS
		vector<int>				v1_int;
		vector<int>				v2_int(500);
		vector<int>				v3_int(0);

		test(v1_int);
		test(v2_int);
		test(v3_int);

		try {
			vector<int>	v4_int(-1);
		} catch (std::exception &e) {
			 cout << ORANGE << "EXCEPTION: " << e.what() << endl << endl; 
		}

		// ? MEMBER FUNCTIONS
		const std::allocator<int>	alloc;

		vector<int> tmp(alloc);

		tmp.push_back(100);
		tmp.erase(tmp.begin());
		
		test(tmp);

		// ? MODIFIERS & CAPACITY
		v1_int.push_back(INT_MIN);
		v1_int.push_back(INT_MAX);
		test(v1_int);

		for (unsigned i = 0; i < v2_int.size(); i++)
			v2_int[i] = i;
		test(v2_int);

		if (v3_int.empty())
		{
			for (unsigned i = 0; i < 72; i++)
				v3_int.push_back(i);
			test(v3_int);
		}
		
	}
	cout << YELLOW;
	cout << "################  STD_MAP  ###############\n" << std::endl;
	cout << NORMAL;
	{

	}
	cout << YELLOW;
	cout << "################ STD_STACK ###############\n" << std::endl;
	cout << NORMAL;
	{

	}

	return (0);
}

#define COLUMNS 10

template <typename T>
void	test(vector<T> v)
{
	static unsigned int	number = 1;

	cout << CYAN << "TEST #" << number++ << " {" << endl;
		cout << GREEN	<< TAB << "size: " << v.size() << endl;
		cout << BLUE	<< TAB << "max_size: " << v.max_size() << endl;
		cout << NORMAL	<< TAB << "capacity: " << v.capacity() << endl;

		unsigned int			i;
		vector<int>::iterator	it;

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
