#include <iostream>
#include <stack>
#include <string.h>
#include <sstream>
#include <vector>
using namespace std;

vector<int> numStore;

int main(void)
{
    vector<string> action;

    while (true)
    {
        while (true)
        {
            string input;
            cin >> input;
            bool error = false;

            if (input == "NUM")
            {
                long long x;
                cin >> x;
                numStore.push_back(x);
            }
            else if (input == "END")
            {
                break;
            }
            else if (input == "BREAK")
            {
                return 0;
            }

            action.push_back(input);
        }
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int c = 0;
            for (int j = 0; j < action.size(); j++)
            {
                bool error = false;
                stack<long long> s;
                int first;
                cin >> first;
                s.push(first);

                if (action[j] == "NUM")
                {
                    long long num = numStore[c++];
                    s.push(num);
                }
                else if (action[j] == "POP")
                {
                    if (s.empty())
                    {
                        error = true;
                    }
                    else
                    {
                        s.pop();
                    }
                }
                else if (action[j] == "INV")
                {
                    if (s.empty())
                    {
                        error = true;
                        break;
                    }
                    long long top = s.top();
                    s.pop();
                    s.push(-top);
                }
                else if (action[j] == "DUP")
                {
                    if (s.empty())
                        error = true;
                    else
                    {
                        long long top = s.top();
                        s.push(top);
                    }
                }
                else if (action[j] == "SWP")
                {
                    if (s.size() < 2)
                        error = true;
                    else
                    {
                        long long top1 = s.top();
                        s.pop();
                        long long top2 = s.top();
                        s.pop();
                        s.push(top1);
                        s.push(top2);
                    }
                }
                else if (action[j] == "ADD")
                {
                    if (s.size() < 2)
                        error = true;
                    else
                    {
                        long long top1 = s.top();
                        s.pop();
                        long long top2 = s.top();
                        s.pop();
                        s.push(top1 + top2);
                    }
                }
                else if (action[j] == "SUB")
                {
                    if (s.size() < 2)
                        error = true;
                    else
                    {
                        long long top1 = s.top();
                        s.pop();
                        long long top2 = s.top();
                        s.pop();
                        s.push(top1 - top2);
                    }
                }
                else if (action[j] == "MUL")
                {
                    if (s.size() < 2)
                        error = true;
                    else
                    {
                        long long top1 = s.top();
                        s.pop();
                        long long top2 = s.top();
                        s.pop();
                        s.push(top1 * top2);
                    }
                }
                else if (action[j] == "DIV")
                {
                    if (s.size() < 2)
                        error = true;
                    else
                    {
                        int neg = 0;

                        long long top1 = s.top();
                        s.pop();
                        long long top2 = s.top();
                        s.pop();

                        if (top1 < 0)
                            neg++;
                        if (top2 < 0)
                            neg++;

                        long long result = top1 / top2;
                        if (neg == 1)
                        {
                            result = (-abs(result));
                        }
                        else
                        {
                            result = abs(result);
                        }

                        s.push(result);
                    }
                }
                else if (action[j] == "MOD")
                {
                    if (s.size() < 2)
                        error = true;
                    else
                    {
                        int neg = 0;

                        long long top1 = s.top();
                        s.pop();
                        long long top2 = s.top();
                        s.pop();

                        if (top1 < 0)
                            neg++;
                        if (top2 < 0)
                            neg++;

                        long long result = top1 % top2;
                        if (neg == 1)
                        {
                            result = (-abs(result));
                        }
                        else
                        {
                            result = abs(result);
                        }

                        s.push(result);
                    }
                }
                cout << s.top() << endl;

                if (error == true || s.size() != 1)
                {
                    cout << "ERROR" << endl;
                }
                else
                {
                    cout << s.top() << endl;
                }
            }
            numStore.clear();
            action.clear();
            cout << endl;
        }
        return 0;
    }
}