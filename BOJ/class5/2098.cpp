#include <iostream>
#include <cmath>
#include <climits>
#include <cstring>

#define INF 987654321
using namespace std;

int N;
int W[16][16];
int D[1 << 16][16];
int answer_bit;
int answer;

void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> W[i][j];
        }
    }

    answer_bit = (1 << N) - 1;
}

int Recursive(int currV, int curri)
{
    if (currV == answer_bit)
    {
        if (W[curri][0] == 0)
            return INF;
        else
            return W[curri][0];
    }

    if (D[currV][curri] != -1)
        return D[currV][curri];
    D[currV][curri] = INF;

    for (int nexti = 0; nexti < N; nexti++)
    {

        if (currV & (1 << nexti)) // 이미 방문한 도시
            continue;

        if (W[curri][nexti] == 0) // 길이 없거나 같은 도시
            continue;

        int nextV = currV | (1 << nexti);
        D[currV][curri] = min(D[currV][curri], (Recursive(nextV, nexti) + W[curri][nexti]));
    }

    return D[currV][curri];
}

void Solution()
{
    memset(D, -1, sizeof(D));
    answer = Recursive(1, 0);
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(NULL);

    Input();
    Solution();

    cout << answer << '\n';

    return 0;
}