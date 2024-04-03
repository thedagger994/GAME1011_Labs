#pragma once
#include <cassert>
#include "UnorderedArray.h"

template<class T>
class Queue
{
public:
	// Constructor
	Queue(int size, int growBy = 1)
	{
		assert(size > 0 && growBy >= 0);
		m_container = new UnorderedArray<T>(size, growBy); // Initializing UnorderedArray
		assert(m_container != nullptr);
	}
	// Destructor
	~Queue()
	{
		if (m_container != nullptr)
		{
			delete m_container;
			m_container = nullptr;
		}
	}

	// Queue Functions
	void push(T val)
	{
		// insertion is still pushing to the first empty element
		assert(m_container != nullptr);
		m_container->push(val);
	}
	void pop()
	{
		// pop() for the queue will remove the first element inserted, this case element at [0]
		assert(m_container != nullptr);
		m_container->remove(0);
	}
	// we'll use the front() function to access the front of the queue, which is element at [0]
	const T& front()
	{
		assert(m_container != nullptr);
		// Dereference our pointer to Uonrdered array then use array notation to return front element
		return (*m_container)[0];
	}

	//Gets and Sets
	int GetSize()
	{
		assert(m_container != nullptr);
		return m_container->GetSize();
	}
	int GetMaxSize()
	{
		assert(m_container != nullptr);
		return m_container->GetMaxSize();
	}
	bool isEmpty()
	{
		assert(m_container != nullptr);
		return (m_container->GetSize() == 0);
	}

private:
	UnorderedArray<T>* m_container;
};