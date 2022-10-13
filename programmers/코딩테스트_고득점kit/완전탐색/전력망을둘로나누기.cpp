#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> wires)
{
    int answer = INT_MAX;

    vector<vector<int>> AL(n + 1);

    for (auto wire : wires)
    {
        AL[wire[0]].push_back(wire[1]);
        AL[wire[1]].push_back(wire[0]);
    }

    for (auto wire : wires)
    {
        int a = wire[0];
        int b = wire[1];
        AL[a].erase(remove(AL[a].begin(), AL[a].end(), b), AL[a].end());
        AL[b].erase(remove(AL[b].begin(), AL[b].end(), a), AL[b].end());

        vector<bool> checked(n + 1, false);
        queue<int> q;
        unordered_set<int> s;
        q.push(1);

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            checked[curr] = true;
            s.insert(curr);
            for (auto a : AL[curr])
            {
                if (!checked[a])
                    q.push(a);
            }
        }

        int s_size = s.size();
        int diff = abs(n - s_size - s_size);
        answer = min(answer, diff);

        AL[a].push_back(b);
        AL[b].push_back(a);
    }

    return answer;
}