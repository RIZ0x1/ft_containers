#include <vector>
#include <iostream>

#define NORMAL	"\033[0m"
#define ORANGE	"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"

#define TAB '\t'

using std::cout;
using std::endl;
using std::vector;

int main()
{
	cout << YELLOW;
	cout << "############### STD_VECTOR ###############\n" << std::endl;
	cout << NORMAL;
	{
		vector<int>		v1_int;
		vector<int>		v2_int();
		vector<int>		v3_int();
		vector<int>		v4_int();

		cout << "CONSTRUCTORS {" << endl;
		cout << TAB << 
		
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