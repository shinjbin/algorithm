#include <iostream>
#include <algorithm>
#include <string>

#define INF 1e8
using namespace std;

int N, M;
int AM[101][101]; // 인접 행렬

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; i <= N; j++)
        {
            if (i != j)
                AM[i][j] = INF;
        }
    }

    int a, b, c;
    for (int i = 1; i <= M; i++)
    {
        cin >> a >> b >> c;
        AM[a][b] = c < AM[a][b] ? c : AM[a][b];
    }

    // 플로이드 워셜 알고리즘
    for (int k = 1; k <= N; k++)
    { // k : 경유지
        for (int i = 1; i <= N; i++)
        { // i : 출발지
            for (int j = 1; j <= N; j++)
            { // j : 도착지
                if (AM[i][j] > AM[i][k] + AM[k][j])
                {
                    AM[i][j] = AM[i][k] + AM[k][j];
                }
            }
        }
    }

    return 0;
}