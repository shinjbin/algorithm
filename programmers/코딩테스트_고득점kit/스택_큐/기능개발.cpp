#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;

    queue<int> days;

    for (int i = 0; i < progresses.size(); i++)
    {
        int todo = 100 - progresses[i];
        if (todo % speeds[i] == 0)
        {
            days.push(todo / speeds[i]);
        }
        else
        {
            days.push(todo / speeds[i] + 1);
        }
    }

    int max_day = days.front();
    days.pop();
    int cnt = 1;
    while (!days.empty())
    {
        int day_now = days.front();
        if (max_day < day_now)
        {
            max_day = day_now;
            answer.push_back(cnt);
            cnt = 0;
        }

        days.pop();
        cnt++;
    }
    answer.push_back(cnt);

    return answer;
}