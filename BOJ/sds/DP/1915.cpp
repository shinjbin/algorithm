#include <iostream>

using namespace std;

int n, m;
int Arr[1000][1000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> Arr[i][j];
        }
    }

    return 0;
}