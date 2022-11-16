#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<vector<int>> jobs)
{
    vector<int> answer;

    int importance[101] = {0};
    int spend_time[101] = {0};

    int nextTime = jobs[0][0];
    int curr_classify_num = 0;
    int max_classify_num = 0;

    int ptr = 0;
    while (ptr < jobs.size())
    {
        while (ptr < jobs.size() && jobs[ptr][0] <= nextTime)
        {
            importance[jobs[ptr][2]] += jobs[ptr][3];
            spend_time[jobs[ptr][2]] += jobs[ptr][1];
            ptr++;
        }
        if (ptr >= jobs.size())
            break;

        max_classify_num = max_element(importance, importance + 101) - importance;

        if (max_classify_num == 0)
        {
            nextTime = jobs[ptr][0] + jobs[ptr][1];
            if (curr_classify_num != jobs[ptr][2])
            {
                curr_classify_num = jobs[ptr][2];
                answer.push_back(jobs[ptr][2]);
            }
            ptr++;
            continue;
        }

        if (!importance[curr_classify_num])
        {
            curr_classify_num = max_classify_num;
            answer.push_back(curr_classify_num);
            nextTime += spend_time[max_classify_num];
            spend_time[max_classify_num] = 0;
        }
        nextTime += spend_time[curr_classify_num];
        spend_time[curr_classify_num] = 0;
        importance[curr_classify_num] = 0;
    }

    importance[curr_classify_num] = 0; //같은 분류번호가 존재하면 제거
    vector<pair<int, int>> todo;
    for (int i = 1; i <= 100; i++)
    {
        if (importance[i])
            todo.push_back({importance[i], -i});
    }
    sort(todo.begin(), todo.end());
    for (int i = todo.size() - 1; i >= 0; i--)
    {
        answer.push_back(-todo[i].second);
    }

    return answer;
}
