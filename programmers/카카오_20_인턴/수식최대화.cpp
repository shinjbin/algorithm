#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long calculate(long long n1, long long n2, char ch)
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
    numbers.push_back(stoi(tmp));

    do
    {
        vector<char> tmp_opers = opers;
        vector<long long> tmp_numbers = numbers;

        for (int i = 0; i < 3; i++)
        {
            char curr_oper = oper_order[i];
            int num_opers = tmp_opers.size();
            for (int j = 0; j < tmp_opers.size(); j++)
            {
                if (tmp_opers[j] == curr_oper)
                {
                    tmp_numbers[j] = calculate(tmp_numbers[j], tmp_numbers[j + 1], curr_oper);
                    tmp_numbers.erase(tmp_numbers.begin() + j + 1);
                    tmp_opers.erase(tmp_opers.begin() + j);
                    j--;
                }
            }
        }

        long long result = tmp_numbers[0];
        if (abs(result) > answer)
            answer = abs(result);

    } while (next_permutation(oper_order.begin(), oper_order.end()));

    return answer;
}