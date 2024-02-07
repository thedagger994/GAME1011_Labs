//#include "Vector2.h"
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	cout << "addition & subtraction test\n";
//	Vector2 v1, v2;
//	v1.x = 1.0f;
//	v1.y = 3.0f;
//	v2.x = 2.0f;
//	v2.y = 4.0f;
//	v1 = v1 + v2;
//	v1.printVector();
//	v1 = v1 - v2;
//	v1.printVector();
//
//	cout << "multiplication & division test\n";
//	// protip: { } works for initializing struct member varibles
//	Vector2 a{ 5.0f, 10.0f };
//	Vector2 b{ 5.0f, 2.0f };
//	Vector2 c = a * b;
//	c.printVector();
//	Vector2 d = a / b;
//	d.printVector();
//
//	cout << "member arithmetic/assignment test\n";
//	Vector2 v3{ 1.0f, 1.0f };
//	v3 += {2.0f, 2.0f};
//	v3.printVector();
//	v3 -= {2.0f, 2.0f};
//	v3.printVector();
//	v3 *= {2.0f, 2.0f};
//	v3.printVector();
//	v3 /= {2.0f, 2.0f};
//	v3.printVector();
//
//	cout << "accessing member variables with array notation test\n";
//	Vector2 v4{ 1.0f, 2.0f };
//	float x = v4[0];
//	cout << "float x is " << x << endl;
//	float y = v4[1];
//	cout << "float y is " << y << endl;
//
//	cout << "modulus test\n";
//	v4 %= Vector2{ 2.0f, 2.0f };
//	v4.printVector();
//	
//	return 0;
//}