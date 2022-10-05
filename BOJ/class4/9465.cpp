#include <iostream>

using namespace std;

int T;
int n;
int sticker[2][100001];
int DP[2][100001];

void Solution()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> sticker[0][i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> sticker[1][i];
    }

    DP[0][1] = sticker[0][1];
    DP[1][1] = sticker[1][1];

    for (int i = 2; i <= n; i++)
    {
        DP[0][i] = max(DP[1][i - 2], DP[1][i - 1]) + sticker[0][i];
        DP[1][i] = max(DP[0][i - 2], DP[0][i - 1]) + sticker[1][i];
    }

    cout << max(DP[0][n], DP[1][n]) << '\n';
}

int main()
{
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        Solution();
    }

    return 0;
}