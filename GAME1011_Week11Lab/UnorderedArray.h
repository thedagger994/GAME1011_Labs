#pragma once
#include <cassert>

template<class T>
class UnorderedArray
{
public:
	//Constructor
	UnorderedArray(int size) : m_array(nullptr), m_maxSize(0), m_numElements(0)
	{
		if (size) // Is this a legal size for an array?
		{
			m_maxSize = size;
			m_array = new T[m_maxSize]; // Dynamically allcating an array to m_maxSize
			memset(m_array, 0, sizeof(T) * m_maxSize); // Explicitly set 0 to all elements in the array
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
	// Fast insertion, find the next empty spot/index
	void push(T val)
	{
		assert(m_array != nullptr);

		if (m_numElements >= m_maxSize) // Check if the array has to expand to accomodate the new data
		{
			// can have a function to expand the array here and then insert
			return;
		}

		// My array has space for a new value. lets add it!
		m_array[m_numElements] = val;
		m_numElements++;
	}

	// Remove the last item inserted int the array
	void pop()
	{
		if (m_numElements > 0)
		{
			m_numElements--; // redue the total number of elements by 1. essentially ignores the last element.
		}
	}

	//Searching: recursive Linear Search (for demo purposes)
	int linearSearch(T searchKey)
	{
		// call to linear recursive search function
		//passing in searchKey, initial lowerBound, initial upperBound
		return linearSearch(searchKey, 0, m_numElements - 1);
	}
	int linearSearch(T searchKey, int first, int last)
	{
		// Did not find value in array
		if (first >= last)
		{
			return -1;
		}
		// Found the value!
		if (m_array[first] == searchKey)
		{
			return first;
		}
		// Increment first and keep searching
		else
		{
			return linearSearch(++first, last, searchKey);
		}
	}

	// Sorting function before Binary Search
	void InsertionSort()
	{
		assert(m_array != nullptr);

		T temp;
		int i = 0;

		// Iterate throught all elements to be sorted starting with index of 1, increseing as more of the array is sorted
		for (int k = 1; k < m_numElements; k++)
		{
			temp = m_array[k];
			i = k;

			//shifting of elements if necessary, create a space for elements to be inserted in correct location
			while (i > 0 && m_array[i - 1] >= temp)// comparing the temp value with previous index, if prev is larger stop
			{
				// push elements to the right
				m_array[i] = m_array[i - 1];
				i--;
			}
			//place the item in temp into the correct location found by last loop (i)
			m_array[i] = temp;
		}
	}

	// recursive Binary Search, needs array to be sorted first
	int binarySearch(T searchKey)
	{
		return binarySearch(searchKey, 0, m_numElements - 1);
	}
	int binarySearch(T searchKey, int lowerBound, int upperBound)
	{
		assert(m_array != nullptr);
		assert(lowerBound >= 0);
		assert(upperBound < m_numElements);

		// bitwise divide by 2 = bitshift 1 to the right
		int current = (lowerBound + upperBound) >> 1;

		//check 1 "base case": did we find the searchKEy at the current index?
		if (m_array[current] == searchKey)
		{
			//we found it! return index
			return current;
		}
		//check 2 "base case": are we done searching
		else if (lowerBound > upperBound)
		{
			//did not find searchKey in m_array
			return -1;
		}
		//check 3: which half of the array is searchKey in?
		else
		{
			if (m_array[current] < searchKey)
			{
				//search the upper half of the array
				return binarySearch(searchKey, current + 1, upperBound);
			}
			else
			{
				//search the lower half of the array
				return binarySearch(searchKey, lowerBound, current - 1);
			}
		}
	}

	// Overloaded [] operator
	T& operator[](int index)
	{
		assert(m_array != nullptr && index < m_numElements);
		return m_array[index];
	}
	// Clear
	void clear()
	{
		m_numElements = 0; // Ignore (or forgets) all current items in the array
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

private:
	// Private Variables
	T* m_array; // Pointer to the beginning of the array

	int m_maxSize; // Maximum size of the array
	int m_numElements; // Number of items currently in the array
};