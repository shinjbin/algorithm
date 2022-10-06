#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    long long result[n + 1];

    result[1] = 1;
    result[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        result[i] = result[i - 1] + result[i - 2];
    }

    cout << result[n] << endl;

    return 0;
}