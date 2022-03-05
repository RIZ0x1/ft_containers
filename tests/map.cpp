#include <map>
#include <string>
#include <iostream>
#include <utility>
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
# define NS	ft
# include "map.hpp"
#endif

using std::cout;
using std::endl;
using NS::map;

template <typename Key, typename Value>
void	print_info(map<Key, Value>& v, const std::string& message);

int main()
{
	map<std::string, std::string> Map;
	print_info(Map, "EMPTY_MAP");

	Map["First_Key"] = "First_Value";
	Map["Second_Key"] = "Second_Value";
	Map["Third_Key"] = "Third_Value";
	print_info(Map, "THREE_ELEMENTS");

	map<std::string, std::string> copyMap;
	copyMap = Map;
	print_info(copyMap, "copyMap");
	{
		map<std::string, std::string> Map2(copyMap);
		print_info(Map2, "CONSTRUCTION_COPY");
	}

	
	/*
	* something with allocator
	*/

	try
	{
		cout << endl << "at(*Right_Key*): " << MAGENTA <<  Map.at("Second_Key");
		cout << CYAN;
		cout << endl << "at(*Wrong_Key*): " << MAGENTA <<  Map.at("Second_Value");
		cout << CYAN << endl;
	}
	catch (std::out_of_range &e)
	{
		cout << ORANGE << "EXCEPTION: " << e.what();
		cout << CYAN << endl;
	}

	cout << endl << "OPERATOR[*RIGHT_KEY*]: " << MAGENTA << Map["Third_Key"];
	cout << CYAN << endl;
	cout << "OPERATOR[*WRONG_KEY*]: " << MAGENTA << Map["Third_Value"];
	cout << CYAN << endl;

	// cout << "ITERATORS (rbegin() AND rend())";
	// for (map<std::string, std::string>::iterator it = Map.rbegin(); it != Map.rend(); it++)
	// {
	// 	cout << endl << TAB2;;
	// 	cout << NORMAL << "{[KEY: " << ORANGE << it->first << NORMAL << "],  [VALUE: " << ORANGE << it->second << NORMAL << "]}";
	// }
	
	Map.clear();
	print_info(Map, "CLEAR");

	Map.insert(std::pair<std::string, std::string>("Inserted_Key1", "Inserted_Value1"));
	Map.insert(std::pair<std::string, std::string>("Inserted_Key2", "Inserted_Value2"));
	Map.insert(std::pair<std::string, std::string>("Inserted_Key3", "Inserted_Value3"));
	Map.insert(std::pair<std::string, std::string>("Inserted_Key4", "Inserted_Value4"));
	Map.insert(std::pair<std::string, std::string>("Inserted_Key5", "Inserted_Value5"));
	Map.insert(std::pair<std::string, std::string>("Inserted_Key6", "Inserted_Value6"));
	Map.insert(std::pair<std::string, std::string>("Inserted_Key7", "Inserted_Value7"));
	Map.insert(std::pair<std::string, std::string>("Inserted_Key8", "Inserted_Value8"));
	Map.insert(std::pair<std::string, std::string>("Inserted_Key9", "Inserted_Value9"));
	Map.insert(std::pair<std::string, std::string>("Inserted_Key10", "Inserted_Value10"));
	Map.insert(std::pair<std::string, std::string>("Inserted_Key6", "Inserted_Value6"));
	// for(map<std::string, std::string>::iterator it = copyMap.begin(); it != copyMap.end(); it++)
	// 	Map.insert(it->first, it->second);
	print_info(Map, "INSERT(10_ELEMENTS)");

	Map.erase("Inserted_Key6");
	print_info(Map, "ERASE_RIGHT_KEY(6)");

	Map.erase(++Map.begin());
	print_info(Map, "ERASE_ITERATOR(SECOND)");

	Map.erase(++(++(++Map.begin())), Map.end());
	print_info(Map, "ERASE_RANGE(FOURTH-END)");

	Map.erase("WRONG_KEY");
	print_info(Map, "ERASE_WRONG_KEY");

	
	Map.swap(copyMap);
	print_info(Map, "SWAP");

	cout << endl << "COUNT(*RIGHT_KEY*): " << MAGENTA << Map.count("First_Key") << CYAN;
	cout << endl << "COUNT(*ANOTHER_RIGHT_KEY*): " << MAGENTA << Map.count("Second_Key") << CYAN;
	cout << endl << "COUNT(*WRONG_KEY*): " << MAGENTA << Map.count("Wrong_Key") << CYAN;
	cout << endl;

	{
		map<std::string, std::string>::iterator it;
		it = Map.find("Second_Key");
		cout << endl << "FIND(*RIGHT_KEY*): " << ORANGE << "[KEY: " << it->first << "], [VALUE: " << it->second << "]" << CYAN;
		it = Map.find("First_Key");
		cout << endl << "FIND(*ANOTHER_RIGHT_KEY*): " << ORANGE << "[KEY: " << it->first << "], [VALUE: " << it->second << "]" << CYAN;
		it = Map.find("Wrong_Key");
		cout << endl << "FIND(*WRONG_KEY*): ";
		if (it != Map.end())
			cout << ORANGE << "[KEY: " << it->first << "], [VALUE: " << it->second << "]" << CYAN;
		else
			cout << GREEN << "ITERATOR REACH END" << CYAN;
		/*
		*	SOMETHING WITH CONST ITERATOR
		*/
	}
	Map.insert(std::pair<std::string, std::string>("Second_Key1", "Second_Value1"));
	{
		std::pair<map<std::string, std::string>::iterator, map<std::string, std::string>::iterator> doubleIt = Map.equal_range("Second_Key");
		cout << endl << endl << "EQUAL_RANGE(*RIGHT_KEY*)";
		cout << endl << ORANGE << "[KEY: " << doubleIt.first->first << "], [VALUE: " << doubleIt.first->second << "]";
		cout << endl << "[KEY: " << doubleIt.second->first << "], [VALUE: " << doubleIt.second->second << "]" << endl << CYAN;
		doubleIt = Map.equal_range("Wrong_Key");
		cout << "EQUAL_RANGE(*WRONG_KEY*)" << endl;
		if (doubleIt.first != Map.end())
		{
			cout << ORANGE << "[KEY: " << doubleIt.first->first << "], [VALUE: " << doubleIt.first->second << "]";
			cout << endl << "[KEY: " << doubleIt.second->first << "], [VALUE: " << doubleIt.second->second << "]";
			cout << CYAN << endl;
		}
		else
			cout << GREEN << "ITERATOR REACH END" << CYAN;
	}

	/*
	*	SOMETHING WITH LOWER_BOUND
	*/

	/*
	*	SOMETHING WITH UPPER_BOUND
	*/
	return 0;
}

template <typename Key, typename Value>
void	print_info(map<Key, Value>& Map, const std::string& message)
{
	cout << endl << CYAN << message << "  {" << endl;
		cout << YELLOW	<< TAB << "is_empty: ";
		if (Map.empty())
			cout << ORANGE << "TRUE" << endl;
		else
			cout << GREEN << "FALSE" << endl;
		cout << GREEN	<< TAB << "size: " << Map.size() << endl;
		cout << BLUE	<< TAB << "max_size: " << Map.max_size() << endl;

		typename map<Key, Value>::iterator	it;

		cout << TAB << MAGENTA << "elements: {" << endl;
		it = Map.begin();
		while (it != Map.end())
		{
			cout << TAB2;
			while (it != Map.end())
			{
				cout << NORMAL << "{[KEY: " << ORANGE << it->first << NORMAL << "],  [VALUE: " << ORANGE << it->second << NORMAL << "]}";
				cout << MAGENTA << endl << TAB2;;
				it++;
			}
			cout << endl;
		}
		cout << TAB2 << '}' << endl;
	cout << CYAN << TAB << '}' << endl;
}