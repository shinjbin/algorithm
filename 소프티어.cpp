#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int main()
{
    int N;

    cin >> N;

    vector<int> answer;

    int dirx[] = {1, 0, -1, 0};
    int diry[] = {0, 1, 0, -1};

    int matrix[10][10];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> matrix[i][j];
        }
    }

    bool checked[10][10] = {false};
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (checked[i][j])
                continue;
            if (matrix[i][j] == 0)
                continue;
            int num = 1;
            queue<pair<int, int>> q;
            q.push({i, j});
            while (!q.empty())
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                checked[x][y] = true;
                num++;

                for (int a = 0; a < 4; a++)
                {
                    int nx = x + dirx[a];
                    int ny = y + diry[a];

                    if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                    {
                        continue;
                    }
                    if (matrix[nx][ny])
                    {
                        q.push({nx, ny});
                    }
                }

                answer.push_back(num);
            }
        }
    }

    sort(answer.begin(), answer.end());
    cout << answer.size() << endl;
    for (int a : answer)
        cout << a << ' ';
    cout << endl;

    return 0;
}