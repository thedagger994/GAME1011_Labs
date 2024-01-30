#pragma once
struct Vector2;

// Overload operator prototype definitions - to be defined in Vector2.cpp
Vector2 operator+(const Vector2& a, const Vector2& b);
Vector2 operator-(const Vector2& a, const Vector2& b);
Vector2 operator*(const Vector2& a, const Vector2& b);
Vector2 operator/(const Vector2& a, const Vector2& b);

bool operator==(const Vector2& a, const Vector2& b);


struct Vector2
{
	Vector2 operator+=(const Vector2& b);
	Vector2 operator-=(const Vector2& b);
	Vector2 operator*=(const Vector2& b);
	Vector2 operator/=(const Vector2& b);

	Vector2 operator%=(const Vector2& b);
	float& operator[](int index);

	void printVector ();
	float x = 0.0f;
	float y = 0.0f;
};