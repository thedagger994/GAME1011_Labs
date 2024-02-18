#pragma once
#include <cassert>

template<typename T>
class Vector
{
public:
	Vector()
	{
		mData = new T[mCapacity];
	}

	~Vector()
	{
		delete[] mData;
		mData = nullptr;
	}

	// Add an element to the end of the vector
	void Push(T value)
	{
		// Re-allocate and copy before appending if we're at capacity
		if (mSize == mCapacity)
		{
			mCapacity++;

			T* newMemory = new T[mCapacity];
			for (size_t i = 0; i < mCapacity; i++)
			{
				newMemory[i] = mData[i];
			}

			delete[] mData;
			mData = newMemory;
		}
		//set our value to the index at mSize, then increment mSize
		mData[mSize++] = value;
	}

	// Remove an element from the end of the vector
	void Pop()
	{
		assert(mSize > 0); // ensure there's elements to remove
		mData[--mSize].~T(); // call T's destructor to ensure whatever we remove gets deallocated
	}

	// Add an arbitrary element to index
	void Insert(const T& element, size_t index)
	{
		assert(index < mSize);
		if (index == mSize - 1)
			Push(element);
		else
		{
			// Todo: push element to mData[index]
			// perhaps a temp vector is needed to shift elements
		}
	}

	// Remove an arbitrary element at given index
	void Erase(size_t index)
	{
		assert(mSize > 0 && index < mSize);
		if (index == mSize - 1)
			Pop();
		else
		{
			// Todo: remove element at mData[index]
			// perhaps a temp vector is needed to shift elements
		}
	}

	// Access any element
	T& operator[](size_t index)
	{
		assert(index < mSize);
		return mData[index];
	}

	// Access the first element
	T& Front()
	{
		assert(mSize > 0);
		return mData[0];
	}

	// Access the last element
	T& Back()
	{
		assert(mSize > 0);
		return mData[mSize - 1];
	}

	// Get the number of elements
	size_t Size()
	{
		return mSize;
	}

private:
	T* mData = nullptr;
	// size_t is similar to uint, positive integer used explicitly for container size
	size_t mSize = 0; // current number of elements
	size_t mCapacity = 2; // max total size, can be increased in Push
};
