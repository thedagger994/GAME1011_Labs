#include <iostream>;
#include "Pancake.h"
using namespace std;

int main ()
{
    PancakeStack<int> pancakeStack;
    CustomerQueue<int> customerQueue;

    int customerCount = 1;
    int pancakesOnStack = 0;

    // Serve 30 customers
    for (int i = 0; i < 30; ++i)
    {
        customerQueue.push (customerCount++);
    }

    // Serve customers until the queue is empty
    while (!customerQueue.isEmpty ())
    {
        int customerNumber = customerQueue.front ();
        customerQueue.pop ();

        cout << "Serving customer #" << customerNumber << "." << endl;

        if (pancakeStack.isEmpty ())
        {
            pancakeStack.addPancakes (5);
            cout << "5 pancakes cooked and added under the lamp." << endl;
            pancakesOnStack += 5;
        }

        int requestedPancakes = 1 + (rand () % 3);
        cout << "Customer #" << customerNumber << " wants " << requestedPancakes << " pancakes." << endl;

        try
        {
            for (int i = 0; i < requestedPancakes; ++i)
            {
                if (pancakeStack.isEmpty ())
                {
                    throw OutOfPancake ();
                }
                pancakeStack.pop ();
                pancakesOnStack--;
            }
            cout << pancakesOnStack << " pancakes left under the lamp." << endl << endl;
        }
        catch (const OutOfPancake& e)
        {
            cerr << "Exception: " << e.what () << endl << endl;
        }
    }

    return 0;
}