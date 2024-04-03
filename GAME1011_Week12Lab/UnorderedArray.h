#pragma once
#include <cassert>

template<class T>
class UnorderedArray
{
public:
	// Constructor
	UnorderedArray(int size, int growBy = 1) :
		m_array(nullptr), m_maxSize(0), m_growSize(0), m_numElements(0)
	{
		if (size) //is this a legal size for the array?
		{
			m_maxSize = size;
			m_array = new T[m_maxSize];; // Dynamically allocating an array to m_maxSize
			memset(m_array, 0, sizeof(T) * m_maxSize); // explicitly set 0 to all elements in the array

			m_growSize = ((growBy > 0) ? growBy : 0);
		}
	}
	// Destructor
	~UnorderedArray()
	{
		if (m_array != nullptr)
		{
			delete[] m_array;
			m_array = nullptr;
		}
	}

	// Insertion
	void push(T val)
	{
		assert(m_array != nullptr);

		if (m_numElements >= m_maxSize) // Check if the array has to expand to accomodate the new data
		{
			Expand();
		}

		// My array has space for a new value, lets add it
		m_array[m_numElements] = val;
		m_numElements++;
	}
	// deletion (2 ways)
	void pop()
	{
		if (m_numElements > 0)
		{
			m_numElements--; // reduce the total number of elements by 1, ignoring the last element
		}
	}
	// Remove an item given an index
	void remove(int index)
	{
		assert(m_array != nullptr);

		if (index >= m_numElements)
		{
			return; // out of bounds index, perhaps some exeption handling here
		}

		for (int i = index; i < m_numElements; i++)
		{
			// Start at the index we want to remove
			// Shift everything after index back by 1
			if (i + 1 < m_numElements)
			{
				m_array[i] = m_array[i + 1];
			}
		}
		m_numElements--;
	}
	// Overloaded [] operator
	T& operator[](int index)
	{
		assert(m_array != nullptr && index < m_numElements);
		return m_array[index];
	}
	//Clear
	void clear()
	{
		m_numElements = 0; //ignore or forgets all current items in the array
	}
	// Gets and Sets
	int GetSize()
	{
		return m_numElements;
	}
	int GetMaxSize()
	{
		return m_maxSize;
	}
	int GetGrowSize()
	{
		return m_growSize;
	}
	int SetGrowSize(int val)
	{
		assert(val >= 0);
		m_growSize = val;
	}

private:
	bool Expand()
	{
		if (m_growSize <= 0)
		{
			//LEAVE
			return false;
		}

		T* temp = new T[m_maxSize + m_growSize];
		assert(temp != nullptr);

		memcpy(temp, m_array, sizeof(T) * m_maxSize);

		delete[] m_array;
		m_array = temp;
		temp = nullptr;

		m_maxSize += m_growSize;

		return true;
	}
	T* m_array; // pointer to the beginning of the array
	int m_maxSize; // Maximum size of the array
	int m_growSize; // amount the array can grow through expansion
	int m_numElements; // numer of items currently in the array
};