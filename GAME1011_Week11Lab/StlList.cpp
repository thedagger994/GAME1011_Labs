#include <iostream>
#include <list>

using namespace std;

int main()
{

    // create a list
    list<int> numbers = { 1, 2, 3, 4, 5 };

    // display the original list 
    cout << "Initial List: ";
    for (int number : numbers)
    {
        cout << number << ", ";
    }

    // add element at the beginning
    numbers.push_front(0);

    // add element at the end
    numbers.push_back(4);

    // display the modified list
    cout << endl << "After Pushing: ";
    for (int number : numbers)
    {
        cout << number << ", ";
    }

    cout << endl;
    // display the first element
    cout << "First Element: " << numbers.front() << endl;

    // display the last element
    cout << "Last Element: " << numbers.back();

    // remove the first element of the list
    numbers.pop_front();

    // remove the last element of the list
    numbers.pop_back();

    // display the modified list 
    cout << endl << "After Popping: ";
    for (int number : numbers)
    {
        cout << number << ", ";
    }

    cout << endl;
    // create an iterator to point to the first element of the list
    list<int>::iterator it = numbers.begin();

    // increment itr to point to the 2nd element
    ++it;

    //display the 2nd element
    cout << "Second Element: " << *it << endl;

    // increment itr to point to the 4th element
    ++it;
    ++it;

    // display the 4th element
    cout << "Fourth Element: " << *it;

    return 0;
}