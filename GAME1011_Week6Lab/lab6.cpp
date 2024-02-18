#include <cassert>
#include <iostream>
#include <string>
#include "Array.h"
#include "Vector.h"
using namespace std;

// One function works for all data types.  This would work
// even for user defined types if operator '>' is overloaded
template<typename T> T myMax(T x, T y)
{
	return (x > y) ? x : y; //terniary operator, evaluates (x > y) and returns x if true, y if false
}

int main()
{
	// Call myMax for int
	cout << myMax<int>(3, 7) << endl;
	// call myMax for double
	cout << myMax<double>(3.0, 7.0) << endl;
	// call myMax for char
	cout << myMax<char>('g', 'e') << endl;

	// This could be better tha native arrays as it has a range check
	Array<float, 2> decimals;
	decimals[0] = 0;
	decimals[1] = 1;
	//decimals[2] = 0; //assertion failed
	cout << decimals[0] << " " << decimals[1] << endl;

	Array<char, 2> chars;
	chars[0] = 'a';
	chars[1] = 'b';
	cout << chars[0] << " " << chars[1] << endl;

	Vector<float> v; //m_data of v will be of float type
	v.Push(1.2);
	v.Pop();
	v.Push(2.4);
	v.Pop();
	v.Push(3.6);
	v.Pop();

	v.Push(4.2);
	v.Push(5.5);
	v.Push(6.3);

	cout << v.Front() << endl;
	cout << v.Back() << endl;
	for (size_t i = 0; i < v.Size(); i++)
	{
		cout << v[i] << endl;
	}

	return 0;
}