#include <iostream>
#include <string>

using namespace std;

struct Test
{
	Test()
	{
		counter++;
		number = counter;
		cout << "Object " << number << " created." << endl;
	}

	~Test()
	{
		cout << "Object " << number << " destroyed." << endl;
	}

	int number;
	static int counter;
};

//Initialize the static variable
//int Test::counter = 0;
//
//int main()
//{
//
//	//Test test1;
//	Test* arrayTest = new Test [100];
//	delete[] arrayTest;
//
//	return 0;
//}