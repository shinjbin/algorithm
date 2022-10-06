#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int tri[505][505];
int n;
int cnt = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> tri[i][j];
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            tri[i][j] += max(tri[i + 1][j], tri[i + 1][j + 1]);
        }
    }

    cout << tri[0][0] << endl;

    return 0;
}