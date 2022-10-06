#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<char> st;

    for (auto i : s)
    {
        if (i == '(')
        {
            st.push(i);
        }
        else if (i == ')')
        {
            if (st.empty())
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }
    }

    if (!st.empty())
        answer = false;

    return answer;
}