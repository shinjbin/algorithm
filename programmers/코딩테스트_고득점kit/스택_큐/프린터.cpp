#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;

    deque<int> q;

    for (auto i : priorities)
    {
        q.push_back(i);
    }

    while (true)
    {
        int curr = q.front();
        bool found = false;
        for (int i = 1; i < q.size(); i++)
        {
            if (q[i] > curr)
            {
                found = true;
                q.push_back(q.front());
                q.pop_front();
                if (location)
                    location--;
                else
                    location = q.size() - 1;
                break;
            }
        }

        if (!found)
        {
            answer++;
            q.pop_front();
            if (location)
                location--;
            else
            {
                break;
            }
        }
    }

    return answer;
}