#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> numbers, int target)
{
    int answer = 0;

    int sz = numbers.size();
    stack<pair<int, int>> s;

    s.push({0, 0});

    while (!s.empty())
    {
        int curr_num = s.top().first;
        int curr_idx = s.top().second;
        s.pop();

        if (curr_idx == sz)
        {
            if (curr_num == target)
                answer++;
            continue;
        }

        s.push({curr_num + numbers[curr_idx], curr_idx + 1});
        s.push({curr_num - numbers[curr_idx], curr_idx + 1});
    }

    return answer;
}