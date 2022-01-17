#include <vector>
#include <climits>
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
		vector<int>				v2_int(1000);
		vector<int>				v3_int(0);

		try { test(v1_int); } catch (std::exception &e) { cout << e.what() << endl; }
		try { test(v2_int); } catch (std::exception &e) { cout << e.what() << endl; }
		try { test(v3_int); } catch (std::exception &e) { cout << e.what() << endl; }
		
		try {
			vector<int>	v4_int(-1);
		} catch (std::exception &e) {
			 cout << ORANGE << "EXCEPTION: " << e.what() << endl << endl; 
		}


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

#define MAX_OUT_ELEMS 10

template <typename T>
void	test(vector<T> v)
{
	cout << "CONSTRUCTORS {" << endl;
		cout << TAB << "size: " << v.size() << endl;
		cout << TAB << "max_size: " << v.max_size() << endl;
		cout << TAB << "capacity: " << v.capacity() << endl;

		unsigned int			i;
		vector<int>::iterator	it;

		cout << TAB << "elements {" << endl;
		i = 0;
		it = v.begin();
		while (it != v.end())
		{
			cout << TAB2 << *it++ << endl;
			if (i++ >= MAX_OUT_ELEMS)
				break ;
		}
		if (v.size() > 10)
			cout << TAB2 << "..." << endl;
	cout << TAB << '}' << endl << endl;
}
