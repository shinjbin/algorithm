#include <iostream>
#include <stack>

using namespace std;

string str;
string answer;

bool isAlpabet(char c)
{
    if (c >= 'A' && c <= 'Z')
        return true;
    return false;
}

int main()
{
    stack<char> s;

    cin >> str;

    for (int i = 0; i < str.size(); i++)
    {
        char c = str[i];
        if (isAlpabet(c))
            answer.push_back(c);

        else
        {
            if (s.empty())
            {
                s.push(c);
                continue;
            }
            if (c == '(')
            {
                s.push(c);
            }

            else if (c == ')')
            {
                while (s.top() != '(')
                {
                    answer.push_back(s.top());
                    s.pop();
                }
                s.pop();
            }

            else if (c == '*' || c == '/')
            {
                while (!s.empty() && (s.top() == '*' || s.top() == '/'))
                {
                    answer.push_back(s.top());
                    s.pop();
                }
                s.push(c);
            }

            else if (c == '+' || c == '-')
            {
                while (!s.empty() && s.top() != '(')
                {
                    answer.push_back(s.top());
                    s.pop();
                }
                s.push(c);
            }
        }
    }

    while (!s.empty())
    {
        answer.push_back(s.top());
        s.pop();
    }

    cout << answer << '\n';

    return 0;
}