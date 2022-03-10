#include <stack>
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
# define NS std
// # include "stack.hpp"
#endif

using std::cout;
using std::endl;
using NS::stack;

template <typename T>
void	print_info(stack<T>& v, const std::string& message);

int main()
{
    stack<std::string> Stack;
    print_info(Stack, "EMPTY_STACK");

    Stack.push("COMMIT");
    print_info(Stack, "ONE_ELEMENT");

    stack<std::string> copyStack;
	copyStack = Stack;
	print_info(copyStack, "copyStack");
	stack<std::string> Stack2(copyStack);
	print_info(Stack2, "CONSTRUCTION_COPY");

    Stack.pop();
    print_info(Stack, "POP_IT");

    if (copyStack != Stack )
        cout << GREEN << "Test" << NORMAL << " '!='" <<GREEN << " is complete successfuly" << CYAN << endl;
    else
        cout << ORANGE <<  "WHAT?! (unexpected result in test " << NORMAL << "'!='" << ORANGE << ")" << CYAN <<  endl;
    if (Stack2 == copyStack)
        cout << GREEN << "Test" << NORMAL << " '=='" <<GREEN << " is complete successfuly" << CYAN << endl;
    else
        cout << ORANGE <<  "WHAT?! (unexpected result in test " << NORMAL << "'=='" << ORANGE << ")" << CYAN <<  endl;
    if (Stack2 > Stack)
        cout << GREEN << "Test" << NORMAL << " '>'" <<GREEN << " is complete successfuly" << CYAN << endl;
    else
        cout << ORANGE <<  "WHAT?! (unexpected result in test " << NORMAL << "'>'" << ORANGE << ")" << CYAN <<  endl;
    if (Stack < Stack2)
        cout << GREEN << "Test" << NORMAL << " '<'" <<GREEN << " is complete successfuly" << CYAN << endl;
    else
        cout << ORANGE <<  "WHAT?! (unexpected result in test " << NORMAL << "'<'" << ORANGE << ")" << CYAN <<  endl;
    return (0);
}

template <typename T>
void	print_info(stack<T>& Stack, const std::string& message)
{
	cout << endl << CYAN << message << "  {" << endl;
		cout << GREEN	<< TAB << "size: " << Stack.size() << endl;
		cout << TAB << MAGENTA << "element on the top: ";
        if (!Stack.empty())
            cout << ORANGE << Stack.top();
        else
            cout << ORANGE << "NULL" << endl;
        cout << CYAN << TAB << '}' << endl;
		cout << endl;
}