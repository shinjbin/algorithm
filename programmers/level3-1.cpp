#include <string>
#include <vector>
#include <queue>

using namespace std;
int MAP[101][101];

struct state
{
    int x;
    int y;
    int step;
};

int directionX[] = {0, 1};
int directionY[] = {1, 0};

int solution(int m, int n, vector<vector<int>> puddles)
{
    queue<pair<int, int>> q;
    bool puddle[m + 1][n + 1];
    int answer = 0;

    for (int i = 0; i < puddles.size(); i++)
    {
        int x = puddles[i][0];
        int y = puddles[i][1];

        puddle[x][y] = true;
    }

    q.push({1, 1});
    while (!q.empty())
    {
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();

        if (currX == m && currY == n)
            answer++;
        if (currX > m)
            continue;
        if (currY > n)
            continue;

        for (int i = 0; i < 2; i++)
        {
            int nextX = currX + directionX[i];
            int nextY = currY + directionY[i];

            if (!puddle[nextX][nextY])
            {
                q.push({nextX, nextY})
            }
        }
    }
    return answer;
}

int main()
{
    int m = 4;
    int n = 3;
    vector<vector<int>> puddles = {{2, 2}};
    cout << solution(m, n, puddles);
}