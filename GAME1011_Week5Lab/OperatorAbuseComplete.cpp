////operators should do what they represent -- cursed example of what NOT to do
//#include <iostream>
//using namespace std;
//
//struct CursedInt 
//{
//	//overloading prefix ex. ++i
//	void operator++()
//	{
//		value--;
//	}
//	//overloadin postfix ex. i++
//	void operator++(int)
//	{
//		value--;
//	}
//
//	void operator--()
//	{
//		value++;
//	}
//	void operator--(int)
//	{
//		value++;
//	}
//
//	int value;
//};
//
//int main()
//{
//	CursedInt num1, num2;
//	num1.value = 1;
//	num2.value = 2;
//	num1++;
//	--num2;
//	cout << "Trying to ++ gives " << num1.value << endl;
//	cout << "Trying to -- gives " << num2.value << endl;
//	
//	//end result: subtracting when we ++ and adding when we --
//	return 0;
//}