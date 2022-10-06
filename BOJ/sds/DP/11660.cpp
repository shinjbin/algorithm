#include <iostream>

using namespace std;

int N, M;
int SumRow[1025][1025];
int Sum[1025][1025];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int num;
            cin >> num;
            SumRow[i][j] = SumRow[i][j - 1] + num;
            Sum[i][j] = Sum[i - 1][j] + SumRow[i][j];
        }
    }

    for (int i = 0; i < M; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        cout << Sum[x2][y2] - Sum[x1 - 1][y2] - Sum[x2][y1 - 1] + Sum[x1 - 1][y1 - 1] << '\n';
    }

    return 0;
}