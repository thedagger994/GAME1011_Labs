#pragma once
// Array implementation of a Stack
#include <cassert>

template <class T>
class Stack
{
public:
	// Constructor
	Stack(int size, int growBy = 1) :
		m_array(nullptr), m_size(0), m_top(-1), m_growSize(0)
	{
		if (size)
		{
			m_size = size;
			m_array = new T[m_size]; 

			memset(m_array, 0, sizeof(T) * m_size); // Explicitly set values to 0

			m_growSize = ((growBy > 0) ? growBy : 0); // set growSize to a positive value or default 0
		}
	}
	// Desturctor
	~Stack()
	{
		if (m_array != nullptr)
		{
			delete[] m_array;
			m_array = nullptr;
		}
	}
	// Stack Functions
	void push(T val)
	{
		assert(m_array != nullptr);

		// Check to see if the stack is full, if it is then expand it
		if (isFull())
		{
			Expand();
		}

		m_array[++m_top] = val; // increment m_top then insert val into the stack
	}

	void pop()
	{
		if (!isEmpty())
		{
			m_top--; // Decrementing top by 1, essentially ignores last element
		}
	}

	const T& top()
	{
		assert(m_array != nullptr);
		assert(m_top >= 0); // check to see if m_top represents an actual element

		return m_array[m_top];
	}

	//Gets and Sets
	int GetSize()
	{
		return m_top + 1;
	}
	int GetMaxSize()
	{
		return m_size;
	}
	bool isEmpty()
	{
		return (m_top == -1); // check to see if stack is empty
	}
	bool isFull()
	{
		return (m_top == m_size - 1); // compare the number of items in the stack to m_size
	}
private:
	bool Expand()
	{
		if (m_growSize <= 0)
		{
			return false;
		}

		//create the new array
		T* temp = new T[m_size + m_growSize];
		assert(temp != nullptr);

		// Copy the element of the original array to the new array
		memcpy(temp, m_array, sizeof(T) * m_size);

		//delete the old array
		delete[] m_array;

		//clean up variables
		m_array = temp;
		temp = nullptr;

		m_size += m_growSize;

		return true;
	}

	T* m_array; // Pointer to the beginning of the array

	int m_top; // representing the top of our array
	int m_size; // size of our stack
	int m_growSize; // how much will the stack grow by
};