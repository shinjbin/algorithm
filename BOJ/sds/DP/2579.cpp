#include <iostream>

using namespace std;

int N;
int stairs[301];
int DP[301][2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> stairs[i];
    }

    // 0은 한칸 불가능, 1은 한칸 가능
    DP[1][0] = stairs[1];
    DP[1][1] = stairs[1];
    for (int i = 2; i <= N; i++)
    {
        if (DP[i - 2][0] > DP[i - 1][1])
        {
            DP[i][0] = DP[i - 2][0] + stairs[i];
            DP[i][1] = DP[i - 2][0] + stairs[i];
        }
        else
        {
            DP[i][0] = DP[i - 1][1] + stairs[i];
            DP[i][1] = DP[i - 2][0] + stairs[i];
        }
    }

    cout << max(DP[N][0], DP[N][1]) << '\n';

    return 0;
}