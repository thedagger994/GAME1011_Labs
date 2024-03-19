#include <iostream>
#include <cassert>
using namespace std;

int Factorial (int x)
{
	assert (x >= 0);

	if (x == 0)
	{
		return 1;
	}

	return (Factorial (x - 1) * x);
}

int DoubleFactorial (int x)
{
	assert (x >= 0);

	if (x == 0 || x == 1)
	{
		return 1;
	}

	return (DoubleFactorial (x - 2) * x);
}

int main ()
{
	cout << "Factorials" << endl;

	cout << "The Factorial of 5: ";
	cout << Factorial(5) << endl;

	cout << "The Double Factorial of 7: ";
	cout << DoubleFactorial(7) << endl;
	return 0;
}