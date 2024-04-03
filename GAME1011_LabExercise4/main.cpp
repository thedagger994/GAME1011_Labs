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