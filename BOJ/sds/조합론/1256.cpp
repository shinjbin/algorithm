#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int N, M;
long long K;
int left = 1, right = 1;
int cnt = 0;

long long DP[101][101];

long long factorial(long long n)
{
    long long result = 1;
    for (int i = 2; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

void combination_dp()
{
    for (int i = 1; i <= 100; i++)
    {
        DP[0][i] = 1;
        DP[i][0] = 1;
    }
    for (int i = 1; i <= 100; i++)
    {
        for (int j = 1; j <= 100; j++)
        {
            DP[i][j] = DP[i][j - 1] + DP[i - 1][j];
            if (DP[i][j] > 1000000000)
                DP[i][j] = 1000000000;
        }
    }
}

void Input()
{
    cin >> N >> M >> K;
}

void FirstChar(int N, int M)
{

    if (N == 0)
    {
        for (int i = 0; i < M; i++)
            cout << 'z';
        cout << endl;
        return;
    }
    if (M == 0)
    {
        for (int i = 0; i < N; i++)
        {
            cout << 'a';
        }
        cout << endl;
        return;
    }
    int c = DP[N - 1][M];
    cnt += c;
    if (K <= cnt)
    {
        cnt -= c;
        cout << 'a';
        FirstChar(N - 1, M);
    }
    else
    {
        cout << 'z';
        FirstChar(N, M - 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    combination_dp();

    if (DP[M][N] < K)
    {
        cout << -1 << endl;
        return 0;
    }
    FirstChar(N, M);

    return 0;
}