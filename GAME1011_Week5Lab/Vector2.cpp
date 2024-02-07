#include "Vector2.h"
#include <cstdlib>
#include <cassert>
#include <iostream>

Vector2 Add(const Vector2& a, const Vector2& b)
{
	Vector2 c;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return c;
}

Vector2 Sub(const Vector2& a, const Vector2& b)
{
	Vector2 c;
	c.x = a.x - b.x;
	c.y = a.y - b.y;
	return c;
}

Vector2 Mul(const Vector2& a, const Vector2& b)
{
	Vector2 c;
	c.x = a.x * b.x;
	c.y = a.y * b.y;
	return c;
}

Vector2 Div(const Vector2& a, const Vector2& b)
{
	Vector2 c;
	c.x = a.x / b.x;
	c.y = a.y / b.y;
	return c;
}

Vector2 Mod(const Vector2& a, const Vector2& b)
{
	Vector2 c;
	c.x = fmodf(a.x, b.x);
	c.y = fmodf(a.y, b.y);
	return c;
}

std::istream& Input(std::istream& in, Vector2& vec)
{
	in >> vec.x;
	in >> vec.y;
	return in;
}

std::ostream& Output(std::ostream& out, const Vector2& vec)
{
	out << "x: " << vec.x << " y: " << vec.y << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, Vector2& vec)
{
	return Input(in, vec);
}

std::ostream& operator<<(std::ostream& out, const Vector2& vec)
{
	return Output(out, vec);
}

bool Equals(const Vector2& a, const Vector2& b)
{
	return a.x == b.x && a.y == b.y;
}

// when given 2 Vector2 objects a + b attempt to add them
Vector2 operator+(const Vector2& a, const Vector2& b)
{
	return Add(a, b);
}

// when given 2 Vector2 objects a - b attempt to subtract them
Vector2 operator-(const Vector2& a, const Vector2& b)
{
	return Sub(a, b);
}

// when given 2 Vector2 objects a * b attempt to multiply them
Vector2 operator*(const Vector2& a, const Vector2& b)
{
	return Mul(a, b);
}

// when given 2 Vector2 objects a / b attempt to divide them
Vector2 operator/(const Vector2& a, const Vector2& b)
{
	return Div(a, b);
}

// when given 2 Vector2 objects a % b attempt to modulus
Vector2 operator%(const Vector2& a, const Vector2& b)
{
	return Mod(a, b);
}

// given the implicit Vector2 a, we will do a += b (a = a + b)
Vector2 Vector2::operator+=(const Vector2& b)
{
	x += b.x;
	y += b.y;
	return *this;
}

// given the implicit Vector2 a, we will do a -= b (a = a - b)
Vector2 Vector2::operator-=(const Vector2& b)
{
	x -= b.x;
	y -= b.y;
	return *this;
}

// given the implicit Vector2 a, we will do a *= b (a = a * b)
Vector2 Vector2::operator*=(const Vector2& b)
{
	x *= b.x;
	y *= b.y;
	return *this;
}

// given the implicit Vector2 a, we will do a /= b (a = a / b)
Vector2 Vector2::operator/=(const Vector2& b)
{
	x /= b.x;
	y /= b.y;
	return *this;
}

// given the implicit Vector2 a, we will do a %= b (a = a % b)
Vector2 Vector2::operator%=(const Vector2& b)
{
	x = fmodf(x, b.x);
	y = fmodf(y, b.y);
	return *this;
}

//get values from your object as if it was an array
float& Vector2::operator[](int index)
{
	assert(index >= 0 && index <= 1); // make sure index is 0-1
	return *((float*)this + index); // access x with index of 0, access y with index of 1
}

//TODO: implement the == equality comparison operator overload
bool operator==(const Vector2& a, const Vector2& b)
{
	return Equals(a, b);
}

bool operator!=(const Vector2& a, const Vector2& b)
{
	return !Equals(a, b);
}

Vector2 Vector2::operator++()
{
	x++;
	y++;
	return *this;
}

Vector2 Vector2::operator++(int)
{
	Vector2 copy = *this;
	x++;
	y++;
	return copy;
}

Vector2 Vector2::operator--()
{
	x--;
	y--;
	return *this;
}

Vector2 Vector2::operator--(int)
{
	Vector2 copy = *this;
	x--;
	y--;
	return copy;
}

void Vector2::printVector()
{
	std::cout << "(" << this->x << ", " << this->y << ")\n";
}