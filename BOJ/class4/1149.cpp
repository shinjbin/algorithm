#include <iostream>
#include <deque>

using namespace std;

int N;
int house[1001][3];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        int r, g, b;
        cin >> r >> g >> b;

        house[i][0] = min(house[i - 1][1], house[i - 1][2]) + r;
        house[i][1] = min(house[i - 1][0], house[i - 1][2]) + g;
        house[i][2] = min(house[i - 1][0], house[i - 1][1]) + b;
    }

    int result = house[N][0];
    for (int i = 1; i < 3; i++)
    {
        result = min(house[N][i], result);
    }
    cout << result << '\n';

    return 0;
}