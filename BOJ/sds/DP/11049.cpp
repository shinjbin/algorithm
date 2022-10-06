#include <iostream>

using namespace std;

int N;
int Matrix[501][2];
int DP[501][501];

inline int mymin(int a, int b) { return a < b ? a : b; }

void Ignition(int a, int b)
{
    DP[a][b] = DP[a + 1][b] + (Matrix[a][0] * Matrix[a][1] * Matrix[b][1]);
    for (int i = a + 1; i < b; i++)
    {
        int tmp = DP[a][i] + DP[i + 1][b] + (Matrix[a][0] * Matrix[i][1] * Matrix[b][1]);
        if (tmp < DP[a][b])
            DP[a][b] = tmp;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> Matrix[i][0] >> Matrix[i][1];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N - i; j++)
            Ignition(j, j + i);
    }

    cout << DP[1][N] << '\n';

    return 0;
}