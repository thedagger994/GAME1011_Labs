#pragma once
#include <cassert>
#include "UnorderedArray.h"

template<class T>
class Stack
{
public:
	// Constructor
	Stack(int size, int growBy = 1)
	{
		assert(size > 0 && growBy >= 0);
		m_container = new UnorderedArray<T>(size, growBy); // Initializing UnorderedArray
		assert(m_container != nullptr);
	}
	// Destructor
	~Stack()
	{
		if (m_container != nullptr)
		{
			delete m_container;
			m_container = nullptr;
		}
	}

	// Stack Function
	void push(T val)
	{
		assert(m_container != nullptr);
		m_container->push(val);
	}
	void pop()
	{
		assert(m_container != nullptr);
		m_container->pop();
	}
	const T& top()
	{
		assert(m_container != nullptr);
		// Dereference our pointer to Unordered array then use array notation to return top element
		return (*m_container)[m_container->GetSize() - 1];
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
		return(m_container->GetSize() == 0);
	}
private:
	UnorderedArray<T>* m_container;
};