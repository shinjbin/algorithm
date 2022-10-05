#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(string dartResult)
{
    int answer = 0;
    vector<int> seq;

    int i = 0, ptr = 0;
    while (i < dartResult.size())
    {
        string temp;
        int num, sqr, opt = 0;

        if (dartResult[i + 1] == '0')
        {
            num = 10;
            if (i + 3 < dartResult.size())
            {
                if (dartResult[i + 3] == '*' || dartResult[i + 3] == '#')
                {
                    temp = dartResult.substr(i, 4);
                }
                else
                {
                    temp = dartResult.substr(i, 3);
                }
            }
            else
            {
                temp = dartResult.substr(i, 4);
            }
        }
        else
        {
            if (i + 2 < dartResult.size())
            {
                if (dartResult[i + 2] == '*' || dartResult[i + 2] == '#')
                {
                    temp = dartResult.substr(i, 3);
                }
                else
                {
                    temp = dartResult.substr(i, 2);
                }
            }
            else
            {
                temp = dartResult.substr(i, 2);
            }
        }

        if (num == 10)
        {
            i += 3;
            if (temp[2] == 'S')
                sqr = 1;
            else if (temp[2] == 'D')
                sqr = 2;
            else if (temp[2] == 'T')
                sqr = 3;

            num = pow(num, sqr);

            if (temp.size() == 4)
            {
                if (temp[3] == '*')
                {
                    if (!seq.empty())
                        seq.back() *= 2;
                    num *= 2;
                }
                if (temp[3] == '#')
                {
                    num *= -1;
                }
                i += 1;
            }
        }
        else
        {
            i += 2;
            if (temp[1] == 'S')
                sqr = 1;
            else if (temp[1] == 'D')
                sqr = 2;
            else if (temp[1] == 'T')
                sqr = 3;

            num = temp[0] - '0';
            num = pow(num, sqr);

            if (temp.size() == 3)
            {
                i += 1;
                if (temp[2] == '*')
                {
                    if (!seq.empty())
                        seq.back() *= 2;
                    num *= 2;
                }
                if (temp[2] == '#')
                {
                    num *= -1;
                }
            }
        }
        seq.push_back(num);
    }

    for (auto i : seq)
    {
        answer += i;
    }
    return answer;
}