#include <iostream>
#include <string>

using namespace std;

bool IsPalindrome (string str, int start, int end)
{
    if (start >= end)
        return true;
    if (str[start] == str[end])
        return IsPalindrome (str, start + 1, end - 1);
    return false;
}

string ReverseString (string str, int start, int end)
{
    if (start >= end)
        return str;
    swap (str[start], str[end]);
    return ReverseString (str, start + 1, end - 1);
}
int main ()
{
    string input;

    //Check for a Palindrome
    cout << "Enter a string to check if it's a palindrome:" << endl;
    getline (cin, input);
    if (IsPalindrome (input, 0, input.length () - 1))
        cout << "\"" << input << "\" is a palindrome." << endl;
    else
        cout << "\"" << input << "\" is not a palindrome." << endl;

    //Reverse a given string
    cout << "Enter a string to reverse: ";
    getline (cin, input);
    cout << "Reversed string: " << ReverseString (input, 0, input.length () - 1) << endl;

    return 0;
}