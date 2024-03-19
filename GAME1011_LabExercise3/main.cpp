#include <iostream>

using namespace std;

template <class T>
class Rectangle
{
private:
    T width;
    T height;

public:
    Rectangle(T w, T h) 
        : width (w), height (h)
    {

    }

    T getWidth()
    {
        return width;
    }

    T getHeight ()
    {
        return height;
    }
};

template <typename T>
T RectangleArea (T side1, T side2)
{
	return (side1 * side2);
}

int main ()
{
    Rectangle<int> intRectangle (5, 10);

    cout << "Int Width: " << intRectangle.getWidth () << endl;
    cout << "Int Height: " << intRectangle.getHeight () << endl;

    cout << "Area: " << RectangleArea (intRectangle.getWidth (), intRectangle.getHeight ()) << endl;

    Rectangle<float> floatRectangle (2, 4);

    cout << "Float Width: " << floatRectangle.getWidth () << endl;
    cout << "Float Height: " << floatRectangle.getHeight () << endl;

    cout << "Area: " << RectangleArea (floatRectangle.getWidth (), floatRectangle.getHeight ()) << endl;

    return 0;
}