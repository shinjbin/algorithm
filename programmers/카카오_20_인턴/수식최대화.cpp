#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <iostream>

using namespace std;

int calculate(int n1, int n2, char ch)
{
    if (ch == '*')
        return n1 * n2;
    else if (ch == '+')
        return n1 + n2;
    else if (ch == '-')
        return n1 - n2;
    else
        exit(0);
}

long long solution(string expression)
{
    long long answer = 0;

    vector<char> oper_order = {'*', '+', '-'};
    vector<long long> numbers;
    vector<char> opers;

    string tmp = "";
    for (char e : expression)
    {
        if (e >= '0' && e <= '9')
        {
            tmp += e;
        }
        else
        {
            numbers.push_back(stoi(tmp));
            tmp = "";
            opers.push_back(e);
        }
    }

    do
    {
        vector<char> tmp_opers = opers;
        for (int i = 0; i < 3; i++)
        {
            char curr_oper = oper_order[i];
            int num_opers = tmp_opers.size();
            for (int j = 0; j < tmp_opers.size(); j++)
            {
                if (opers[j] == curr_oper)
                {
                    numbers[j] = numbers[j] + numbers[j + 1];
                    numbers.erase(numbers.begin() + j + 1);
                    tmp_opers.erase(tmp_opers.begin() + j);
                    j--;
                }
            }
        }

        long long result = numbers[0];
        if (abs(result) > answer)
            answer = abs(result);

    } while (next_permutation(oper_order.begin(), oper_order.end()));

    return answer;
}