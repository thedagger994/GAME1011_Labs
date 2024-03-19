#include <iostream>
#include <cassert>
using namespace std;

int TriNumberLoop (int term)
{
	assert (term >= 1);

	int value = 0;

	for (; term > 0; term--)
	{
		value += term;
	}

	return value;
}

//Triangle number with recursion
int TriNumRecursion (int term)
{
	assert (term >= 1);

	if (term == 1)
	{
		return 1;
	}

	//Since We know T1 = 1 we can work backwards, T2 = T1 + 2
	return (TriNumRecursion (term - 1) + term);
}

//int main ()
//{
//	cout << "Triangle number Example!" << endl;
//
//	cout << "The value of the 6th term using a loop is: ";
//	cout << TriNumberLoop (6) << endl;
//}