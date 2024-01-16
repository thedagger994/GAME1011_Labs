 #include <iostream>
using namespace std;

//int main()
//{
//	char letter = 'a';                      //& gets the memory address
//	cout << "Memory address of letter is: " << long(&letter) << endl;
//
//	int x = 25; // int variable
//	int* ptr; //pointer variable, point to an integer
//
//	//ptr = x; //does not work
//	ptr = &x; //works, stores the address of an int x to ptr
//	cout << "Value of x is: " << x << endl;
//	cout << "Memory address of x is: " << long(ptr) << endl;
//
//	cout << "Print x using x and ptr: \n";
//	cout << x << " " << *ptr << endl; //*ptr is the dereferencing operation, get the value it is pointing to
//
//	*ptr = 100; // what ptr is pointing to will now = 100
//	cout << "Print x using x and ptr: \n";
//	cout << x << " " << *ptr << endl;
//	//x has been modified by *ptr = 100 as ptr was pointing to x
//
//	int y = 100;
//	cout << "Value of y is: " << y << endl;
//	ptr = &y; //reassign ptr to the address of y
//	*ptr *= 10; // operate on the value at the address value = value * 10
//	cout << "Value of y is now: " << y << endl; //y has been changed
//
//	int arr[] = { 10, 20, 30, 40, 50 };
//	cout << "Value of *arr: " << *arr << endl; //*arr = 10 as *arr points to the beginning of the array
//	for (int i = 0; i < 5; i++)
//	{
//		ptr = &arr[i]; // ptr = address at arr[i]
//		cout << long(ptr) << " "; //gap of 8 bytes between the elements of arr in memory
//	}
//	return 0;
//	// note we only used 1 ptr variable, just modified what it points to!
//}