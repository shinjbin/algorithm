#include <string.h>
#include <vector>
#include <queue>
#include <climits>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY)
{
    int answer = INT_MAX;

    bool checked[102][102] = {false};
    int MAP[102][102];
    memset(MAP, -1, sizeof(MAP));
    int dirX[] = {-1, 0, 1, 0};
    int dirY[] = {0, -1, 0, 1};

    int destX = itemX * 2;
    int destY = itemY * 2;

    // MAP 설정
    for (auto r : rectangle)
    {
        int minX = r[0] * 2;
        int minY = r[1] * 2;
        int maxX = r[2] * 2;
        int maxY = r[3] * 2;

        for (int x = minX; x <= maxX; x++)
        {
            for (int y = minY; y <= maxY; y++)
            {
                if (x == minX || x == maxX || y == minY || y == maxY)
                {
                    if (MAP[x][y] != 0)
                        MAP[x][y] = 1;
                }
                else
                {
                    MAP[x][y] = 0;
                }
            }
        }
    }

    // BFS
    queue<pair<int, pair<int, int>>> q; // first is distance, second is coordinate
    q.push({0, {characterX * 2, characterY * 2}});
    while (!q.empty())
    {
        int dist = q.front().first;
        int currX = q.front().second.first;
        int currY = q.front().second.second;
        q.pop();

        if (currX == destX && currY == destY)
        {
            answer = min(answer, dist);
            continue;
        }

        for (int i = 0; i < 4; i++)
        {
            int nextX = currX + dirX[i];
            int nextY = currY + dirY[i];

            if (!checked[nextX][nextY] && MAP[nextX][nextY] == 1)
            {
                q.push({dist + 1, {nextX, nextY}});
            }
        }

        checked[currX][currY] = true;
    }

    return answer / 2;
}