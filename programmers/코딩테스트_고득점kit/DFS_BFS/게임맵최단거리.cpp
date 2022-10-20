#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> maps)
{
    int answer = -1;

    int dirx[] = {1, 0, -1, 0};
    int diry[] = {0, 1, 0, -1};

    int n = maps.size();
    int m = maps[0].size();

    vector<vector<bool>> checked(n, vector<bool>(m, false));

    queue<pair<int, pair<int, int>>> q;
    q.push({0, {0, 0}});

    while (!q.empty())
    {
        int x = q.front().second.first;
        int y = q.front().second.second;
        int cnt = q.front().first;
        q.pop();

        if (x < 0 || y < 0 || x >= n || y >= m)
        {
            continue;
        }
        if (!maps[x][y])
            continue;
        if (checked[x][y])
            continue;
        checked[x][y] = true;

        if (x == n - 1 && y == m - 1)
            answer = cnt + 1;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dirx[i];
            int ny = y + diry[i];
            q.push({cnt + 1, {nx, ny}});
        }
    }

    return answer;
}