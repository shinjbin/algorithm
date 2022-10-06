#include <iostream>
#include <string>
#include <cstring>

#define MAX 50

using namespace std;

int N, M;
int map[MAX][MAX];
bool visit[MAX][MAX];
int DP[MAX][MAX];
int answer;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

void input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] == 'H')
                map[i][j] = 0;
            else
                map[i][j] = s[j] - '0';
        }
    }
}

int DFS(int x, int y)
{
    if (x < 0 || y < 0 || x >= N || y >= M || map[N][M] == 0)
        return 0;
    if (visit[x][y] == true)
    {
        cout << -1 << endl;
        exit(0);
    }

    if (DP[x][y] != -1)
        return DP[x][y];

    visit[x][y] = true;
    DP[x][y] = 0;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + (map[x][y] * dx[i]);
        int ny = y + (map[x][y] * dy[i]);
        DP[x][y] = max(DP[x][y], DFS(nx, ny) + 1);
    }
    visit[x][y] = false;
    return DP[x][y];
}

void solution()
{
    memset(DP, -1, sizeof(DP));
    answer = DFS(0, 0);
    cout << answer << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solution();

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << map[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}