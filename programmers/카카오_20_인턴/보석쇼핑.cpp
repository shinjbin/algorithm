#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <deque>

using namespace std;

vector<int> solution(vector<string> gems)
{
    vector<int> answer = {1, 100000};
    unordered_set<string> gems_set;
    unordered_map<string, int> gems_map;
    deque<string> deq;

    for (int i = 0; i < gems.size(); i++)
    {
        gems_set.insert(gems[i]);
        gems_map[gems[i]] = 0;
    }
    int start = 1, end = 1;

    int cnt = 0;
    for (int i = 0; i < gems.size(); i++)
    {
        end = i + 1;
        string gem = gems[i];
        deq.push_back(gem);

        // 없었던 보석의 경우
        if (gems_map[gem] == 0)
        {
            cnt++;
        }
        gems_map[gem]++;

        while (gems_map[deq.front()] > 1)
        {
            gems_map[deq.front()]--;
            deq.pop_front();
            start++;
        }

        if (cnt == gems_set.size())
        {
            if (end - start < answer[1] - answer[0])
            {
                answer = {start, end};
            }
        }
    }

    return answer;
}