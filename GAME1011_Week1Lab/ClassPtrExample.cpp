////Class with pointers example
//#include <iostream>
//using namespace std;
//
//class Rectangle
//{
//public:
//	Rectangle() : width(nullptr), height(nullptr)
//	{
//		cout << "rectangle default constructor called\n";
//		width = new int; // new keyword is needed to assign a memory address to width
//		height = new int;  
//	}
//	Rectangle(int w, int h) : width(nullptr), height(nullptr)
//	{
//		cout << "rectangle parameterized constructor called\n";
//		width = new int; 
//		height = new int;
//		*width = w; // set the value of what width is pointing to to w
//		*height = h;
//		// shortcut width = new int(w)
//	}
//	~Rectangle()
//	{
//		//destructor needed if we use the "new" keyword to allocate memory
//	}
//	void setWidth(int w)
//	{
//		*width = abs(w); // set the value of what width is pointing to to w
//	}
//	void setHeight(int h)
//	{
//		*height = abs(h); // set the value of what height is pointing to to h
//	}
//	int getWidth()
//	{
//		return *width; // get the value of the int width is pointing to
//	}
//	int getHeight()
//	{
//		return *height; // get the value of the int height is pointing to
//	}
//	int getArea()
//	{
//		return getWidth() * getHeight();
//	}
//	int getPerimeter()
//	{
//		return (2 * getWidth() + 2 * getHeight());
//	}
//private:
//	int* width;
//	int* height;
//};
//
//int main()
//{
//	Rectangle rect(5, 6);
//
//	cout << "Width and Height are: " << rect.getWidth() << ", " << rect.getHeight() << endl;
//	cout << "Total Area of rect: " << rect.getArea() << endl;
//	cout << "Total Perimeter of rect: " << rect.getPerimeter() << endl;
//
//	rect.setWidth(6);
//	rect.setHeight(7);
//	cout << "after setting w/h, Width and Height are: " << rect.getWidth() << ", " << rect.getHeight() << endl;
//	cout << "Total Area of rect: " << rect.getArea() << endl;
//	cout << "Total Perimeter of rect: " << rect.getPerimeter() << endl;
//
//	Rectangle rect1; // using default constructor
//	rect1.setWidth(3);
//	rect1.setHeight(4);
//	cout << "Total Area of rect1: " << rect1.getArea() << endl;
//	cout << "Total Perimeter of rect1: " << rect1.getPerimeter() << endl;
//
//	//create a pointer to a rectangle, and use the new keyword to create a Rectangle object at that address
//	Rectangle* pRect = new Rectangle(4, 5);
//
//	cout << "Area of pRect using . operation: " << (*pRect).getArea() << endl; // what we want to do
//	cout << "Area of pRect using -> operation: " << pRect->getArea() << endl; // simplified 
//	//for pointer of objects we use the -> operator to use member functions
//
//	return 0;
//}