#include <iostream>
#include <bits/stdc++.h>
#include <queue>
using namespace std;

struct state
{
    int x;
    int y;
    int chance;
};

int N, M;
char MAP[1001][1001];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int answer[1001][1001];
int visited[1001][1001][2];

int BFS()
{
    queue<state> q;

    visited[1][1][1] = 1;
    q.push({1, 1, 1});

    while (!q.empty())
    {
        state temp = q.front();
        q.pop();

        int currX = temp.x;
        int currY = temp.y;
        int chance = temp.chance;

        if (currX == N && currY == M)
            return visited[currX][currY][chance];

        for (int i = 0; i < 4; i++)
        {
            int nx = temp.x + dx[i];
            int ny = temp.y + dy[i];
            if (nx < 1 || ny < 1 || nx > N || ny > M)
                continue;

            if (MAP[nx][ny] == '1' && chance)
            {
                visited[nx][ny][chance - 1] = visited[currX][currY][chance] + 1;
                q.push({nx, ny, chance - 1});
            }
            if (MAP[nx][ny] == '0' && visited[nx][ny][chance] == 0)
            {
                visited[nx][ny][chance] = visited[currX][currY][chance] + 1;
                q.push({nx, ny, chance});
            }
        }
    }
    return -1;
}

int main()
{
    cin >> N >> M;
    queue<state> q;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> MAP[i][j];
        }
    }

    cout << BFS() << '\n';

    return 0;
}