#include <iostream>
#include <cstring>

using namespace std;

int T;
int M, N, K;
int farm[51][51];
int checked[51][51];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

void Input()
{
    cin >> T;
}

void DFS(int x, int y)
{
    checked[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= M || ny < 0 || ny >= N)
            continue;

        if (farm[nx][ny] == 1)
        {
            if (!checked[nx][ny])
            {
                DFS(nx, ny);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int result = 0;
        cin >> M >> N >> K;

        memset(checked, false, sizeof(checked));
        memset(farm, 0, sizeof(farm));

        for (int j = 0; j < K; j++)
        {
            int x, y;
            cin >> x >> y;
            farm[x][y] = 1;
        }

        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (farm[i][j] == 1)
                {
                    if (!checked[i][j])
                    {
                        result++;
                        DFS(i, j);
                    }
                }
            }
        }

        cout << result << '\n';
    }

    return 0;
}