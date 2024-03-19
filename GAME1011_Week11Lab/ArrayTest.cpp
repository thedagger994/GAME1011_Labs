#include <iostream>
#include "UnorderedArray.h"
using namespace std;

int main()
{
	UnorderedArray<double> array(5);

	array.push(80.8);
	array.push(64.4);
	array.push(99.9);
	array.push(76.6);
	array.push(5.5);
	array.pop();

	cout << "Printing out our Array: ";
	for (int i = 0; i < array.GetSize(); i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;

	cout << "Linear search for 80.8 was found at index: ";
	cout << array.linearSearch(80.8);
	cout << endl;

	array.InsertionSort();
	cout << "Printing out our Array after InsertionSort: ";
	for (int i = 0; i < array.GetSize(); i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;

	cout << "Binary search for 80.8 was found at index: ";
	cout << array.binarySearch(80.8);
	cout << endl;
	return 0;
}