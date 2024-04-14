#pragma once
#include <stdexcept>
#include <stack>
#include <queue>
using namespace std;

class OutOfPancake : public exception
{
public:
    const char* what () const noexcept override
    {
        return "Out of Pancakes!";
    }
};

template <typename T>
class PancakeStack : public stack<T>
{
public:
    // When no stack
    bool isEmpty () const
    {
        return this->empty ();
    }

    // Adding to the stack
    void addPancakes (int numPancakes)
    {
        for (int i = 0; i < numPancakes; ++i)
        {
            this->push (i + 1);
        }
    }
};

template <typename T>
class CustomerQueue : public queue<T>
{
public:
    // When no queue
    bool isEmpty () const
    {
        return this->empty ();
    }
};