#include <iostream>
//#include "Stack.h"
#include "StackArray.h"
using namespace std;

int main()
{
	//cout << "Stack using simple Stack Class" << endl << endl;
	cout << "Stack using StackArray Class" << endl << endl;

	Stack<int> sStack(5);

	sStack.push(101);
	sStack.push(501);
	sStack.push(201);
	sStack.push(301);
	sStack.push(401);
	sStack.push(901); // should call expand here
	sStack.pop();
	sStack.pop();
	// final stack 301, 201, 501, 101

	cout << "Contents of the stack: ";
	while (!sStack.isEmpty())
	{
		cout << " " << sStack.top();
		sStack.pop();
	}
	cout << endl << endl;
	return 0;
}