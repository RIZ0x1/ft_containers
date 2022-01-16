#include <vector>
#include <iostream>

#define NORMAL	"\033[0m"
#define ORANGE	"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"

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
		vector<int>				v1_int;
		vector<int>				v2_int(0);
		vector<int>				v3_int();
		vector<int>				v4_int();

		test(v1_int);
		test(v2_int);
		test(v3_int);
		test(v4_int);
		
	}
	cout << YELLOW;
	cout << "################  STD_MAP  ###############\n" << std::endl;
	cout << ORANGE;
	{

	}
	cout << YELLOW;
	cout << "################ STD_STACK ###############\n" << std::endl;
	cout << BLUE;
	{

	}

	return (0);
}

template <typename T>
void	constructors(vector<T> v)
{
	vector<int>::iterator	it;

	cout << "CONSTRUCTORS {" << endl;
		cout << TAB << v1_int.size() << endl;
		cout << TAB << v1_int.capacity() << endl;

		cout << TAB << "elements {" << endl;
		it = v1_int.begin();
		for (it; it != v1_int.end(); it++)
		{ cout << TAB2 << *it << endl; }
		cout << TAB << '}' << endl;
}
