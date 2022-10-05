#include <iostream>

using namespace std;

int N, K;
pair<int, int> item[101];
int DP[101][100001];

int main()
{
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        int W, V;
        cin >> W >> V;
        item[i] = {W, V};
    }

    for (int i = 1; i <= N; i++)
    {
        int w = item[i].first;
        int v = item[i].second;
        for (int j = 1; j <= K; j++)
        {
            if (w > j)
                DP[i][j] = DP[i - 1][j];
            else
                DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - w] + v);
        }
    }

    cout << DP[N][K] << '\n';

    return 0;
}