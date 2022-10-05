#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2)
{
    int answer = -2;
    long long sum1 = 0, sum2 = 0;

    queue<int> q1;
    queue<int> q2;

    for (auto i : queue1)
    {
        sum1 += i;
        q1.push(i);
    }
    for (auto i : queue2)
    {
        sum2 += i;
        q2.push(i);
    }

    int cnt = 0;
    while (true)
    {
        if (cnt > 2 * (queue1.size() + queue2.size()))
        {
            answer = -1;
            break;
        }

        if (sum1 > sum2)
        {
            int tmp = q1.front();
            sum1 -= tmp;
            sum2 += tmp;
            q2.push(tmp);
            q1.pop();
        }
        else if (sum2 > sum1)
        {
            int tmp = q2.front();
            sum1 += tmp;
            sum2 -= tmp;
            q1.push(tmp);
            q2.pop();
        }
        else
        {
            answer = cnt;
            break;
        }

        cnt++;
    }

    return answer;
}