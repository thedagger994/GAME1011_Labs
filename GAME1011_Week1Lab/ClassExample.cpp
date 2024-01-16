//Inherited class example
#include <iostream>
using namespace std;

class Rectangle
{
public:
	Rectangle() // Default constructor will be called by derived class constructor (Square)
	{

	}
	Rectangle(int w, int h) : width(w), height(h) // shortform for assigning w and h to width and height
	{
		cout << "rectangle parameterized constructor called\n";
	}
	void setWidth(int w)
	{
		width = abs(w);
	}
	void setHeight(int h)
	{
		height = abs(h);
	}
	int getWidth()
	{
		return width;
	}
	int getHeight()
	{
		return height;
	}
	int getArea()
	{
		return getWidth() * getHeight();
	}
	int getPerimeter()
	{
		return (2 * getWidth() + 2 * getHeight());
	}
private:
	int width;
	int height;
};

class Square : public Rectangle // Inherited from rectangle class
{
public:
	Square(int w)
	{
		cout << "square constructor called\n";
		setWidth(w);
		setHeight(w);
	}
};

//int main()
//{
//	Rectangle rect(5, 6); // take in 2 int values for the constructor (width, height)
//	Square sq(5); // take in 1 int value for the square constructor (w)
//
//	cout << "Total Area of rect: " << rect.getArea() << endl;
//	cout << "Total Perimeter of rect: " << rect.getPerimeter() << endl;
//
//	cout << "Total Area of sq: " << sq.getArea() << endl;
//	cout << "Total Perimeter of sq: " << sq.getPerimeter() << endl;
//
//	sq.setWidth(4); // can call functions from rectangle class
//	sq.setHeight(6);
//	cout << "Total area of sq after set w/h: " << sq.getArea() << endl;
//	cout << "Total perimeter of sq after set w/h: " << sq.getPerimeter() << endl;
//
//	return 0;
//}