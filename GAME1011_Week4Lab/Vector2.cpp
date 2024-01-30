#include "Vector2.h"
#include <cstdlib>
#include <cassert>
#include <iostream>

// When given 2 Vector2 objects a + b attempt to add them
Vector2 operator+(const Vector2& a, const Vector2& b)
{
	Vector2 c;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return c;
}

// When given 2 Vector2 objects a - b attempt to subtract them
Vector2 operator-(const Vector2& a, const Vector2& b)
{
	Vector2 c;
	c.x = a.x - b.x;
	c.y = a.y - b.y;
	return c;
}

// When given 2 Vector2 objects a * b attempt to multiply them
Vector2 operator*(const Vector2& a, const Vector2& b)
{
	Vector2 c;
	c.x = a.x * b.x;
	c.y = a.y * b.y;
	return c;
}

// When given 2 Vector2 objects a / b attempt to divide them
Vector2 operator/(const Vector2& a, const Vector2& b)
{
	Vector2 c;
	c.x = a.x / b.x;
	c.y = a.y / b.y;
	return c;
}

// When given the implicit Vector2 a, we will do a += b ( a = a + b)
Vector2 Vector2::operator+=(const Vector2& b)
{
	x += b.x;
	y += b.y;
	return *this;
}

// When given the implicit Vector2 a, we will do a -= b ( a = a - b)
Vector2 Vector2::operator-=(const Vector2& b)
{
	x -= b.x;
	y -= b.y;
	return *this;
}

// When given the implicit Vector2 a, we will do a *= b ( a = a * b)
Vector2 Vector2::operator*=(const Vector2& b)
{
	x *= b.x;
	y *= b.y;
	return *this;
}

// When given the implicit Vector2 a, we will do a /= b ( a = a / b)
Vector2 Vector2::operator/=(const Vector2& b)
{
	x /= b.x;
	y /= b.y;
	return *this;
}

// When given the implicit Vector2 a, we will do a %= b ( a = a % b)
Vector2 Vector2::operator%=(const Vector2& b)
{
	x = fmodf(x, b.x);
	y = fmodf(y, b.y);
	return *this;
}

// Get values from your object as if it was an array
float& Vector2::operator[](int index)
{
	assert (index >= 0 && index <= 1); // Make sure index is 0-1
	return *((float*)this + index); // Access x with index of 0. Y with index of 1.
}

//TODO: implement the == equality comparison operator overload

bool operator==(const Vector2& a, const Vector2& b)
{
	return (a.x == b.x && a.y == b.y);
}

void Vector2::printVector ()
{
	std::cout << "(" << this->x << ", " << this->y << ")\n";
}