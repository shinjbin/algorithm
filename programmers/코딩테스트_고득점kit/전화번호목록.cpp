#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book)
{
    bool answer = true;

    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < phone_book.size() - 1; i++)
    {
        string left = phone_book[i];
        string right = phone_book[i + 1];
        if (left.size() < right.size())
        {
            if (left == right.substr(0, left.size()))
            {
                return false;
            }
        }
        else
        {
            if (right == left.substr(0, right.size()))
            {
                return false;
            }
        }
    }

    return answer;
}